#include <string.h>

#include "number.h"

int is_num(char* str) {

    int l = strlen(str);
    char* p = str;

    for (int i = 0; i < l; i++, p++) {
        if (*p < '0' || *p > '9') return 0;
    }

    return 1;
}