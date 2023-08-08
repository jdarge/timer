#include <stdlib.h>

#include "audio.h"
#include "keyboard.h"

AUDIO* audio_init (char* file) {

	mpg123_init();
    ao_initialize();

    AUDIO* a = (AUDIO*) malloc(sizeof(AUDIO));

    init_handle(a);
    if (!a->mh) goto handle;

    init_err(a, file);
    if(a->err) goto err;

    init_format(a);

    init_dev(a);
    if (!a->dev) goto dev;

    if(0) {
    dev:
    err: 
        free(a->mh);
    handle:

        return NULL;
    }

    return a;
}

void init_handle (AUDIO* a) {

	mpg123_handle* mh = mpg123_new(NULL, NULL);
    if (mh == NULL) {
        fprintf(stderr, "Error initializing mpg123\n");
        a->mh = NULL;;
    }

    a->mh = mh;
}

void init_err (AUDIO* a, char* mp3) {
	
	int err;

	err = mpg123_open(a->mh, mp3);
    if (err != MPG123_OK) {
        fprintf(stderr, "Cannot open file: %s\n", mpg123_strerror(a->mh));
        a->err = 1;
    }

    a->err = err;
}

void init_format (AUDIO* a) {
    int channels, encoding;
    long rate;

    mpg123_getformat(a->mh, &rate, &channels, &encoding);

    ao_sample_format format;
    format.bits = mpg123_encsize(encoding) * 8;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    a->format = format;
}

void init_dev (AUDIO* a) {
    ao_device* dev = ao_open_live(ao_default_driver_id(), &a->format, NULL);
    if (dev == NULL) {
        fprintf(stderr, "Error opening audio device\n");
        a->dev = NULL;
    }

    a->dev = dev;
}

void play_alarm (AUDIO* a) {
    size_t buffer_size = mpg123_outblock(a->mh);
    char* buffer = (char*) malloc(buffer_size);

    do {// Play alarm until [ENTER] is used 
        size_t done;
        a->err = mpg123_read(a->mh, buffer, buffer_size, &done);
        if (a->err == MPG123_DONE) {
            mpg123_seek(a->mh, 0, SEEK_SET);
            continue;
        } else if (a->err != MPG123_OK) {
            fprintf(stderr, "Error reading MP3 data: %s\n", mpg123_strerror(a->mh));
            break;
        }

        ao_play(a->dev, buffer, done);
    } while (!kbhit());

    free(buffer);
}

void audio_clean (AUDIO* a) {
    if(a->dev)
        ao_close(a->dev);
    if(a->mh) {
        mpg123_close(a->mh);
        mpg123_delete(a->mh);
    }
    mpg123_exit();
    ao_shutdown();
}
