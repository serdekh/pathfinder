#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL) {
        return -2;
    }
    
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

// void test_print_index(const char *str, char c) {
//     printf("'%s':\n\tlooking for symbol '%c'\n\tresult: %d\n\n", str, c, mx_get_char_index(str, c));
// }

// int main() {
//     char *str1 = "yes i am russofob";
//     char *str2 = "quetions?";
//     char *str3 = NULL;

//     test_print_index(str1, 'i');
//     test_print_index(str2, 'F');
//     test_print_index(str3, 'd');
// }

