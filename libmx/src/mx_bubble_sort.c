#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
	int swap_count = 0;

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
				char *t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				swap_count++;
			}
		}
	}

	return swap_count;
}

