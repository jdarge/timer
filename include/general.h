#ifndef TIMER_GENERAL_INCLUDED
#define TIMER_GENERAL_INCLUDED

#define CYAN "\033[1m\033[36m"
#define CLEAR "\033[0m"
 
void display_help ();
int check_arguments (int argc, char** argv);
void clear_line();

#undef is_second

int is_second(char* s);
int is_minute(char* s);
int is_hour(char* s);
int is_format(char* s);

#endif
