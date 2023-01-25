#include "../inc/libmx.h"

void *mx_memccpy(void * restrict dst, const void * restrict src, int c, size_t n) {
    unsigned char *dststr = (unsigned char *)dst;
    unsigned char *srcstr = (unsigned char *)src;
    unsigned char ccopy = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        dststr[i] = srcstr[i];
        
        if (srcstr[i] == ccopy) {
            return &(dststr)[i + 1];
        }       
    }

    return NULL;
}

// #include <string.h>
// #define N 18
// #define N_COPIED 18

// int main() {
//     char s1[N] = "This is an example";
//     char s2[N] = "This is an example";

//     char *dst1 = (char*)malloc(sizeof(char) * N);
//     char *dst2 = (char*)malloc(sizeof(char) * N);
//     char c = ' ';

//     printf("\n\tmx_memccpy: %s", (char *)mx_memccpy(dst1, s1, c, N_COPIED));
//     printf("\n\t   memccpy: %s", (char *)memccpy(dst2, s2, c, N_COPIED));

//     free(dst1);
//     free(dst2);
    
//     return 0;
// }
