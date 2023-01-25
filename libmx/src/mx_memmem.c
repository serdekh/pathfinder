#include "../inc/libmx.h"

void *mx_memmem(const void* big, size_t big_len, const void *little, size_t little_len) {
    char *string = (char *)big;

    for (size_t i = 0; i < big_len; i++) {
        if (mx_memcmp((const void *)(string + i), little, little_len) == 0) {
            return &string[i];
        }
    } 

    return NULL;
}

// #include <string.h>

// void test_get_str_input(char *text, char *s) {
//     printf("%s", text);
//     scanf("%s", s);
//     printf("\n");
// }

// int main () {
//     char string[30];
//     char substring[30];
    
//     while (true) {
//         test_get_str_input("string   \t", string);
//         test_get_str_input("substring\t", substring);

//         char *resmx = mx_memmem(string, 30, substring, 30);
//         char *res = memmem(string, 30, substring, 30);

//         printf("\n\t=====================\n\tmx_memmem: %s\n\t=====================\n\t\n\n", resmx);
//         printf("\n\t   memmem: %s\n\t=====================\n\t\n\n", res); 
//     }
    
//     return(0);
// }
