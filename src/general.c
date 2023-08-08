#include <stdio.h>
#include <string.h>

#include "general.h"
#include "number.h"
#include "strtonum.h"

void display_help () {
    printf(
        "General timer options:\n"
        "\t--help\t\t\tDisplays this screen.\n"
        "\t-s, --second\t\tInput second(s) before alarm rings.\n"
        "\t-m, --minute\t\tInput minute(s) before alarm rings.\n"
        "\t-h, --hour\t\tInput hour(s) before alarm rings.\n"
        "\t-f, --format\t\tFor more specific timers.\n"
        "\t\t\t\t\t\tFormat: hhmmss\n"
        "\t\t\t\t\t\tExample: -f 031530\n"
        "\t\t\t\t\t\t\t will run for 03 hours, 15 minutes, 30 seconds\n"
    );
}

int check_arguments(int argc, char** argv) {

    // TODO: CLEAN THIS UP!

    if(
        strcmp(argv[1], "--help") != 0 &&
        !is_second(argv[1]) &&
        !is_minute(argv[1]) &&
        !is_hour(argv[1]) &&
        !is_format(argv[1])
    )  goto FAULT;

    if (strcmp(argv[1], "--help") == 0) return -1;
    if (argc < 3) return -1; // failed to input a number, only entered flag

    const char* errstr;

    if (!is_num(argv[2])) 
        return -2;

    if (is_format(argv[1])) {
        // TODO: should allow the use of unlimited hours?
        //       for now, it's left to double digit hours
        if (strlen(argv[2]) != 6) 
            return -1;
        strtonum(argv[2], 1, 999999, &errstr);
    } else {
        strtonum(argv[2], 0, 0, &errstr);
    }

    if (errstr) {
        printf("ERROR: STRTONUM; number is %s\n", errstr);
    FAULT:
        return 1;
    }

    return 0;
}

void clear_line() {
    printf("\r\033[K");
}

int is_second(char* s) {
    if (strcmp(s, "-s") != 0 &&
        strcmp(s, "--second") != 0
    ) {
        return 0;
    }

    return 1;
}

int is_minute(char* s) {
    if (strcmp(s, "-m") != 0 &&
        strcmp(s, "--minute") != 0
    ) {
        return 0;
    }

    return 1;
}

int is_hour(char* s) {
    if (strcmp(s, "-h") != 0 &&
        strcmp(s, "--hour") != 0
    ) {
        return 0;
    }

    return 1;
}

int is_format(char* s) {
    if (strcmp(s, "-f") != 0 &&
        strcmp(s, "--format") != 0
    ) {
        return 0;
    }

    return 1;
}
