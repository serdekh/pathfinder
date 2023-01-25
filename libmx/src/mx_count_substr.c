#include "../inc/libmx.h"


int mx_count_substr(const char *str, const char *sub) {
	if (str == NULL || sub == NULL) {
		return -1;
	}
	if (mx_strcmp(sub, "") == 0) {
		return 0;
	}

	int count = 0;
	int strlen = mx_strlen(str);
	int sublen = mx_strlen(sub);

	for (int i = 0; i < strlen; i++) {
		bool isValid = true;
		int k = 0;
		for (int j = i; j < i + sublen; j++) {
			if (str[j] != sub[k]) {
				isValid = false;
			}
			k++;
		}

		if (isValid) {
			count++;
		}
	}

	return count;
}

// int main() {
// 	char str[] = "yo, yo, yo Neo";
// 	char sub[] = "yo";

// 	int r1 = mx_count_substr(str, sub); //returns 3 
// 	int r2 = mx_count_substr(str, NULL); //returns -1 
// 	int r3 = mx_count_substr(NULL, sub); //returns -1

// 	printf("%d\n%d\n%d\n", r1, r2, r3);
// }
