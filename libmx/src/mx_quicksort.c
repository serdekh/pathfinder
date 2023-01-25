#include "../inc/libmx.h"

void mx_swap(char **arr, int i, int j, int *swap_count) {
    char *temporary = arr[i];
    arr[i] = arr[j];
    arr[j] = temporary;

    (*swap_count)++;
}

int mx_quicksort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int swap_count = 0;

    while (i != j) {
        if ((mx_strlen(arr[i]) > mx_strlen(arr[j])) == (i < j)) {
            mx_swap(arr, i, j, &swap_count);

            int p = i;
            i = j;

            if (p < j) {
                j = p + 1;
            }
            else {
                j = p - 1;
            }
        } 
        else {
            if (i < j) {
                j--;
            }
            else {
                j++;
            }
        }
    }

    if (left < i - 1)
        swap_count += mx_quicksort(arr, left, i - 1);
    if (i + 1 < right)
        swap_count += mx_quicksort(arr, i + 1, right);


    return swap_count;
}


// void TEST_print_quick_sorted_array(char **arr, int to, int *swap_count) {
//     printf("{ ");
//     for (int i = 0; i < to - 1; i++) {
//         printf("%s, ", arr[i]);
//     }

//     printf("%s } (swaps = %d)\n", arr[to - 1], *swap_count);   
//     *swap_count = 0;
// }


// int main() {
//     char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
//     char *arr1[] = {"DMC", "Clint Eastwood", "Dr Brown", "Einstein", "Jessica", "Biff Tannen"};
//     int swap_count = 0;
//     TEST_print_quick_sorted_array(arr, 4, &swap_count);
//     swap_count = mx_quicksort(arr, 0, 3);
//     TEST_print_quick_sorted_array(arr, 4, &swap_count);
//     printf("\n\n");
//     TEST_print_quick_sorted_array(arr1, 6, &swap_count);
//     swap_count = mx_quicksort(arr1, 0, 5);
//     TEST_print_quick_sorted_array(arr1, 6, &swap_count);
// }

