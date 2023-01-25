#include "../inc/libmx.h"

void mx_strdel(char **str) {
	free(*str);
	*str = NULL;
}

// #include <string.h>

// int main() {
// 	char *str = malloc(sizeof(char) * 10);
// 	strcpy(str, "text");
// 	printf("%s\n", str);
// 	mx_strdel(&str);
// 	printf("%s\n", str);
// }

