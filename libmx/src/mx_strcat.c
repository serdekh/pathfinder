#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, char *restrict s2) {
    char* ptr = s1 + mx_strlen(s1);
    while (*s2 != '\0') {
        *ptr++ = *s2++;
    }
    *ptr = '\0';
    return s1;
}

// #include <string.h>

// int main() {
// 	char aboba[100] = "'aboba '";
// 	char a[20] = "'is a funny word'";

// 	mx_strcat(aboba, a);

// 	printf("%s", aboba);

// }

