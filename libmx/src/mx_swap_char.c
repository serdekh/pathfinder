#include "../inc/libmx.h"

void mx_swap_char(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL) 
        return;    

    char temporary;

    temporary = *s2;
    *s2 = *s1;
    *s1 = temporary;
}

// int main() {
//     char campus_str[6] = "campus";

//     printf("original: %s\n", campus_str);

//     mx_swap_char(&campus_str[1], &campus_str[4]);

//     printf("swaped [1] and [4] elements!\n");

//     printf("result: %s", campus_str);~
