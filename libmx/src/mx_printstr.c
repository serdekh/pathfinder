#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        mx_printchar(s[i]);
    }
}

