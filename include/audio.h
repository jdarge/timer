#ifndef TIMER_AUDIO_INCLUDED
#define TIMER_AUDIO_INCLUDED

#include <mpg123.h>
#include <ao/ao.h>

typedef struct AUDIO {
    mpg123_handle *mh;
    ao_device *dev;
    ao_sample_format format;
    int err;
} AUDIO;

AUDIO *audio_init(char *file);

void init_handle(AUDIO *a);

void init_err(AUDIO *a, char *mp3);

void init_format(AUDIO *a);

void init_dev(AUDIO *a);

void play_alarm(AUDIO *a);

void audio_clean(AUDIO *a);

#endif
