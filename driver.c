#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#include "audio.h"
#include "general.h"
#include "timer.h"

volatile bool allow_input = false;

void* input_thread();

int main (int argc, char** argv) {

    // used to capture user input prior to timer going off
    pthread_t input_thread_id;
    pthread_create(&input_thread_id, NULL, input_thread, NULL);

    if (argc == 1 || argc > 3) {
    FAULT:
        display_help();
        return 1;
    }

    int check = check_arguments(argc, argv);
    if (check > 0) return 1; // strtonum error
    if (check < 0) { // formatting error
        goto FAULT;
    }

    char* alarm = "/usr/local/share/timer/sound/alarm.mp3";
    AUDIO* a = audio_init(alarm);
    if(!a) return 1;

    int t = timer(argv);
    if(t) return 1;

    play_alarm(a);
    pthread_join(input_thread_id, NULL);

    audio_clean(a);
    free(a);

    return 0;
}

void* input_thread() {
    int c;
    while (!allow_input) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            allow_input = true;
            break;
        }
    }
    return NULL;
}


/* 
TODO: 
# dnf install mpg123-devel
# dnf install libao-devel
*/

