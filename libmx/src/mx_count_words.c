#include  "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int strlen = mx_strlen(str);
    int words = 0;

    for (int i = 0; i < strlen; i++) {
        if (str[i] != c && (i == 0 || str[i - 1] == c)) {
            words++;
        }
    }

    return words;
}

// int main() {
//     char str[] = "  follow  *   the  white rabbit ";
//     printf("mx_count_words(str, '%c') = %d\n", '*', mx_count_words(str, '*'));
//     printf("mx_count_words(str, '%c') = %d\n", ' ', mx_count_words(str, ' '));
//     printf("mx_count_words(str, '%c') = %d\n", ' ', mx_count_words(NULL, '*'));
//     printf("mx_count_words(str, '%c') = %d\n", 't', mx_count_words(str, 't'));
// }
