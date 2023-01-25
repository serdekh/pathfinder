#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
	for (int i = 0; ; i++) {
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		if (s1[i] == '\0' && s2[i] == '\0')
			return 0;
	}
}

// #include <string.h>

// int main() {
// 	char *dst1 = malloc(sizeof(char) * 100);
// 	char *dst2 = malloc(sizeof(char) * 100);

// 	while (1) {
// 		printf("write first str ");
// 		scanf("%s", dst1);
// 		printf("write second str ");
// 		scanf("%s", dst1);
// 		printf("\n\tmx_strcmp: %d\n\tstrcmp:    %d\n\n", mx_strcmp(dst1, dst2), strcmp(dst1, dst2));
// 		free(dst1);
// 		free(dst2);
// 		dst1 = malloc(sizeof(char) * 10);
// 		dst2 = malloc(sizeof(char) * 10);
// 	}
// }
