#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "general.h"
#include "timer.h"
#include "strtonum.h"

int timer (char** str) {

	int duration = get_time_in_s(str[1], str[2]);

	time_t start_time = time(NULL);
    time_t end_time = start_time + duration;

    while (time(NULL) < end_time) {
        time_t remaining_time = end_time - time(NULL);
        int hours = remaining_time / 3600;
        int minutes = (remaining_time % 3600) / 60;
        int seconds = remaining_time % 60;

        clear_line();
        printf("Time remaining: %02d:%02d:%02d\r", hours, minutes, seconds);
        fflush(stdout);

        // Delay for one second
        sleep(1);
    } 

    clear_line();
    printf("Time remaining: 00:00:00");

    printf("\n%sALERT!%s\n", CYAN, CLEAR);

    return 0;
}

int get_time_in_s(char* str, char* num) {

    int duration;
    const char* errstr;
    char h[3], m[3], s[3]; 

    if(is_format(str)) {
        goto format;
    }

    duration = (int) strtonum(num, 0, 0, &errstr);
    if(is_minute(str))
        duration *= 60;
    if(is_hour(str))
        duration *= 3600;

    if(0) {
    format:
        h[0]=num[0];h[1]=num[1];h[2]='\0';
        m[0]=num[2];m[1]=num[3];m[2]='\0';
        s[0]=num[4];s[1]=num[5];s[2]='\0';

        duration =  (int) strtonum(h, 0, 99, &errstr) * 3600;
        duration += (int) strtonum(m, 0, 99, &errstr) * 60;
        duration += (int) strtonum(s, 0, 99, &errstr);
    }

    return duration;
}