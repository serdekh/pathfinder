#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    for (i = 0; i < len && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }

    while (i < len) {
        dst[i] = '\0';
        i++;
    }

    return dst;
}

// #include <string.h>

// int main() {
//     const int SIZE = 6;
//     int n = 15;
//     char dst1[SIZE];
//     char dst2[SIZE];
//     char *str = "this is a string";
//     printf("mx_strncpy: %s\nstrncpy: %s", mx_strncpy(dst1, str, n), strncpy(dst2, str, n));
// }

