#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *str = (unsigned char *)s;

    for (size_t i = 0; i < n; i++) {
        if (str[i] == c) {
            return &(str[i]);
        }
    }

    return NULL;
}

// #include <string.h>

// int main () {
//     char str[30];
//     char c[30];
//     int n = 0;

//     while (true) {
//         printf("str:\t");
//         scanf("%s", str);
//         printf("\n");

//         printf("n:\t");
//         scanf("%d", &n);
//         printf("\n");

//         printf("c:\t");
//         scanf("%s", c);
//         printf("\n");

//         printf("\n\tLook for symbol %c in %s with length %d...\n\n\n", c[0], str, n);
//         char *resmx = (char*)mx_memchr(str, c[0], n);
//         char *res = (char*)memchr(str, c[0], n);

//         printf("\n\tmx_memchr: %s\n", resmx);
//         printf("\n\t   memchr: %s\n\n", res); 

//         (mx_strcmp(resmx, res) == 0)
//             ? printf("\n\tPERFECT!\n\n")
//             : printf("\n\tFAILURE!\n\n");
//     }
    
//     return 0;
// }
