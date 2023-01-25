#include "../inc/libmx.h"

char *mx_strndup(const char *str, size_t n) {
    size_t length = 0;
	char *duplicate = NULL;

	for (; (length < n) && str[length]; length++) {}

    duplicate = malloc(length + 1);

	if (duplicate == NULL)
		return NULL;

	mx_strncpy(duplicate, str, length);

	duplicate[length] = '\0';

	return duplicate;
}

// int main() {
//     char str[16] = "aaaaaaaabbbbbbbb";
//     char *copy;

//     copy = mx_strndup(str, 9);

//     printf("%s", copy);
//     free(copy);
//     return 0;
// }
