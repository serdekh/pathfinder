#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *string = (char *)s;
    size_t string_length = mx_strlen(string);

    for (size_t i = string_length - 1; i > string_length - n; i--) {
        if (string[i] == c) {
            return &string[i];
        }
    }

    return NULL;
}

// void test_get_result(char *s, char c, int n) {
//     printf("mx_memrchr(%s, %c, %d) = '%s'\n", s, c, n, mx_memrchr(s, c, n));
// }

// int main() {
//     test_get_result("Trinity", 'i', 7);
//     test_get_result("Trinity", 'M', 7);
//     return 0;
// }
