#include "../inc/libmx.h"

bool mx_is_extra_space_character(char c) {
    return (c == '\t' || c == '\f' || c == '\n' || c == '\r' || c == '\v');
}

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL || mx_strcmp(str, "") == 0) {
        return NULL;
    }

    char *trimmed = mx_strtrim(str);

    if (trimmed == NULL || mx_strcmp(str, "") == 0) {
        return NULL;
    }

    int trimmedlen = mx_strlen(trimmed);

    int whitespaces = 0;

    for (int i = 0; i < trimmedlen; i++) {
        if (mx_is_extra_space_character(trimmed[i])) {
            whitespaces++;
        }
        if (!mx_is_extra_space_character(trimmed[i - 1]) && mx_is_extra_space_character(trimmed[i])) {
            whitespaces++;
        }
    }

    char *result = mx_strnew(trimmedlen - whitespaces);

    int j = 0;

    for (int i = 0; i < trimmedlen; i++) {
        if (!mx_is_extra_space_character(trimmed[i])) {
            result[j] = trimmed[i];
            j++;
        }
        if (!mx_is_extra_space_character(trimmed[i - 1]) && mx_is_extra_space_character(trimmed[i])) {
            result[j] = ' ';
            j++;
        }
    }

    free(trimmed);

    return result;
    
}

// void TEST_print_whitespaces(char *str) {
//     if (str == NULL) {
//         printf("(null)\n");
//         return;
//     }
//     printf("'");
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (mx_is_extra_space_character(str[i])) {
//             printf("■");
//         }
//         else {
//             printf("%c", str[i]);
//         }
//     }

//     printf("'\n");
// }

// int main() {
//     char *name = "\t\tI\n\f\tlove\tnigga's\t\t\t\f\f\fcocks\t\t\t\n\n\tvery\n\n\nmuch";

//     printf("Before: ");
//     TEST_print_whitespaces(name);
//     char *result = mx_del_extra_spaces(name);

//     printf("After: ");
//     TEST_print_whitespaces(result);
//     free(result);
// }
