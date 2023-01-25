#include "../inc/libmx.h"

void *mx_memcpy(void * restrict dst, const void * restrict src, size_t n) {
    unsigned char *dststr = (unsigned char *)dst;
    unsigned char *srcstr = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        dststr[i] = srcstr[i];
    }

    return dst;
}

// #include <string.h>

// #define N 18
// #define N_COPIED 3
// int main() {
//     char s1[N] = "This is an example";
//     char s2[N] = "This is an example";

//     char *dst1 = (char*)malloc(sizeof(char) * N);
//     char *dst2 = (char*)malloc(sizeof(char) * N);

//     dst1 = (char*)mx_memcpy(dst1, s1, N_COPIED);
//     dst2 = (char*)memcpy(dst2, s2, N_COPIED);

//     printf("\n\tmx_memcpy: %s", dst1);
//     printf("\n\t   memcpy: %s", dst2);

//     free(dst1);
//     free(dst2);
    
//     return 0;
// }
