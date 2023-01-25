#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *realloced_ptr = NULL;

    if (size > 0) {
		if (ptr != NULL) {
			return (void *)malloc(size);
        }
		
        realloced_ptr = (void *)malloc(size);
		
        if (realloced_ptr != NULL) {
			mx_memcpy(realloced_ptr, ptr, size);
			free(ptr);
		}
	}

    return realloced_ptr;
}
