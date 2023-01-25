#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr == NULL || delim == NULL) {
        return;
    }
    
    int length = 0;
    
    for (; arr[length] != NULL;) {
        length++;
    }

    for (int i = 0; i < length - 1; i++) {
        mx_printstr(arr[i]);
        mx_printstr(delim);
    }

    mx_printstr(arr[length - 1]);
    mx_printstr("\n");
}

// int main() {
//     char *arr[] = {"J", "o", "P", "A"};
//     mx_print_strarr(arr, ", ");
// }
