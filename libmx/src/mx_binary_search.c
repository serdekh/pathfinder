#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (arr == NULL || *arr == NULL || size < 0 || s == NULL || count == NULL) {
        return -1;
    }

    int left = 0;
    int middle = size / 2;
    int right = size - 1;

    while (left <= right) {
        middle = (left + right) / 2;

        *count += 1;
        int cmp = mx_strcmp(arr[middle], s);

        if (cmp == 0) {
            return middle;
        } 
        else if (cmp > 0) {
            right = middle - 1;
        } 
        else if (cmp < 0) {
            left = middle + 1;
        }
    }

    *count = 0;

    return -1;
}

// int main() {
//     char *arr[6] = {"222", "Abcd", "aBc", "ab", "az", "z"};
//     int count = 0;
//     printf("%d", mx_binary_search(arr, 6, "ab", &count)); //returns 3 and count = 3
//     printf(" %d\n", count);
//     count= 0;
//     printf("%d", mx_binary_search(arr, 6, "aBc", &count)); //returns 2 and count = 1
//     printf(" %d\n", count);
//     count= 0;
//     printf("%d", mx_binary_search(arr, 6, "aBz", &count)); //returns -1 and count = 0
//     printf(" %d\n", count);
// }
