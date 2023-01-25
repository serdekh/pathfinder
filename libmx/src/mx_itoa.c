#include "../inc/libmx.h"

char *mx_itoa(int number) {
    // :)
    if (number == -2147483648) {
        return "-2147483648";
    }
    if (number == 2147483647) {
        return "2147483647";
    }

    char *result = NULL;
    int size = 0;
    int temporary = number;

    if (number == 0) {
        result = mx_strnew(1);
        result[0] = '0';
        return result;
    }

    if (temporary < 0) {
        size++;
        temporary *= -1;
    }

    while(temporary != 0) {
        temporary /= 10;
        size++;
    }

    result = mx_strnew(size);

    if (number < 0) {
        result[0] = '-';
        number *= -1;
    }

    result[size--] = '\0';

    while ((number != 0 && size >= 0) && (result[size] != '-')) {
        result[size--] = (number % 10) + '0';
        number /= 10;
    }

    return result;
}

// int main() {
//     for (int i = 0; i < 352452345; i++) {
//         char *s = mx_itoa(i);
//         printf("'%s'\n", s);
//         free(s);
//     }
// }
