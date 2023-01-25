#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *dststr = (char *)dst;
    char *srcstr = (char *)src;

    char *allocated = malloc(len);

    for (int i = 0; i < (int)len; i++)
        allocated[i] = srcstr[i];

    for (int i = 0; i < (int)len; i++)
        dststr[i] = allocated[i];

    return dst;
}

