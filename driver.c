#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#include "audio.h"
#include "general.h"
#include "keyboard.h"
#include "number.h"
#include "timer.h"

volatile bool allowInput = false;

void* inputThread(void* arg) {
    int c;
    while (!allowInput) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            allowInput = true;
            break;
        }
    }
    return NULL;
}

int main (int argc, char** argv) {

    // used to capture user input prior to timer going off
    pthread_t inputThreadId;
    pthread_create(&inputThreadId, NULL, inputThread, NULL);

    if (argc == 1 || argc > 3) {
        display_help();
        return 1;
    }

    int check = check_arguments(argc, argv);
    if (check > 0) return 1; // strtonum error
    if (check < 0) { // formatting error
        display_help();
        return 1;
    }

    char* alarm = "sound/alarm.mp3";// TODO: fix for install path?
    AUDIO* a = audio_init(alarm);
    if(!a) return 1;

    int t = timer(argv);
    if(t) return 1;

    play_alarm(a);
    pthread_join(inputThreadId, NULL);

    audio_clean(a);
    free(a);

    return 0;
}



/* 
TODO: 
# dnf install mpg123-devel
# dnf install libao-devel
*/