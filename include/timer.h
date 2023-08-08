#ifndef TIMER_TIMER_INCLUDED
#define TIMER_TIMER_INCLUDED

#define SECOND 1 
#define MINUTE 2
#define HOUR 3 
#define FORMAT 4

int timer (char** str);
int get_time_in_s(char* str, char* num);

#endif