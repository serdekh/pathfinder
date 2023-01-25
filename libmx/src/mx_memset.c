#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *str = (unsigned char*)b;

    for (size_t i = 0; i < len; i++) {
        str[i] = c;
    }
    
    return b;
}

// #include <string.h>

// int main() {
//     char str[] = "AAAAAAAAAAAAAAAAA";
//     char str_copy[] = "AAAAAAAAAAAAAAAAA";
//     printf("%s", str);
//     printf("\n\tmx_memset: %s", (char *)mx_memset(str, 'a', 1));
//     printf("\n\t   memset: %s", (char *)memset(str_copy, 'a', 1));
//     return 0;
// }
