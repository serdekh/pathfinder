#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
	int i = 0;

	for (i = 0; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}

	dst[i] = '\0';

	return dst;
}

// #include <string.h>

// int main() {
// 	char *dst1 = malloc(sizeof(char) * 10);
// 	char *dst2 = malloc(sizeof(char) * 10);

// 	char s[100];

// 	while (1) {
// 		printf("write any text ");
// 		scanf("%s", s);
// 		printf("\n\tmx_strcpy: %s\n\tstrcpy:    %s\n\n", mx_strcpy(dst1, s), strcpy(dst2, s));
// 		free(dst1);
// 		free(dst2);
// 		dst1 = malloc(sizeof(char) * 10);
// 		dst2 = malloc(sizeof(char) * 10);
// 	}
// }
