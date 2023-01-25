#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int length = 0;

    while (s[length] != '\0') {
        length++;
    }

    return length;
}

// void test_get_len(const char *s) {
//     printf("%s => %d\n", s, mx_strlen(s));
// }

// int main() {
//     char *str1 = "love";
//     char *str2 = "nuhat";
//     char *str3 = "bebru";

//     test_get_len(str1);
//     test_get_len(str2);
//     test_get_len(str3);
// }

