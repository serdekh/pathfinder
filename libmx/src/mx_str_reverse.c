#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	if (s == NULL) {
		return;
	}

    int length = mx_strlen(s);
	
	for (int i = 0; i < length / 2; i++) {
		mx_swap_char(&s[i], &s[length - 1 - i]);
	}
}

// int main(int argc, char *argv[]) {

//     for (int i = 1; i < argc; i++) {
// 		printf("Before: '%s'\n", argv[i]);
// 		mx_str_reverse(argv[i]);
// 		printf("Reversed: '%s'\n\n", argv[i]);
// 	}

//     return 0;
// }

