#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int strlen = mx_strlen(str);
	char *duplicate = mx_strnew(strlen + 1);

    if (duplicate == NULL) {
        return NULL;
    }

    mx_strcpy(duplicate, str);

    return duplicate;
}

// int main() {
// 	char *arr = "example string for tests";
// 	printf("Source string: '%s'\n", arr);
// 	char *arr_copy = mx_strdup(arr);
	
// 	if (arr_copy == NULL) {
// 		printf("Copied string is NULL");
// 		return 0;
// 	}

// 	printf("Copied string: '%s'", arr_copy);
// }

