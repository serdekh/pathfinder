#include "../inc/libmx.h"

bool mx_is_white_space_character(char c) {
    return (c == '\t' || c == '\f' || c == '\n' || c == ' ' || c == '\r' || c == '\v');
}

char *mx_strtrim(const char *str) {
    if (str == NULL || (mx_strcmp(str, "") == 0)) {
        return NULL;
    }

    int strlen = mx_strlen(str);
    int i = 0;
    int j = strlen;

    while (mx_is_white_space_character(str[i])) {
        i++;
    }

    while (mx_is_white_space_character(str[j - 1])) {
        j--;
    }

    int resultlen = j - i;

    char *result = mx_strnew(resultlen);

    for (int k = 0; k < resultlen; k++) {
        result[k] = str[k + i];
    }

    return result;
}

// void TEST_print_str_whitespaces(char *str) {
//     printf("'");
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (mx_is_white_space_character(str[i])) {
//             printf("[W]");
//         }
//         else {
//             printf("%c", str[i]);
//         }
//     }
//     printf("'\n");
// }

// int main() {
//     char *name= "\f\n\n\n\n\n\n\t\r\v    My name... is Neo\t\n\t\f\r\v\t\t\t";
//     printf("before: ");
//     TEST_print_str_whitespaces(name);
//     char *trimmed = mx_strtrim(name);
//     printf("Result: ");
//     TEST_print_str_whitespaces(trimmed);
//     free(trimmed);
// }
