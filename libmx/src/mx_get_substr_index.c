#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
	if (s1 == NULL || s2 == NULL || n <= 0)
		return 0;

	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		if (s1[i] == '\0' && s2[i] == '\0')
			return 0;
	}

	return 0;
}

int mx_get_substr_index(const char *str, const char *sub) {
	if (str == NULL || sub == NULL) {
		return -2;
	}

    int len = mx_strlen(str);
	int substrlen = mx_strlen(sub);
	int count = 0;

	for (int i = 0; i < len; i++) {
        count = 0;

        for (int j = 0; j < substrlen; j++) {
            if (str[i + j] == sub[j]) {
                count++;
            }
        }

        if (count == substrlen) {
            return i;
        }
    }
	
	return -1;
}

// int main() {
//     int example1 = mx_get_substr_index("McDonalds", "Don"); //returns 2
//     int example2 = mx_get_substr_index("McDonalds Donuts", "on"); //returns 3
//     int example3 = mx_get_substr_index("McDonalds", "Donatello"); //returns -1
//     int example4 = mx_get_substr_index("McDonalds", NULL); //returns -2
//     int example5 = mx_get_substr_index(NULL, "Don"); //returns -2

//     printf("%d\n%d\n%d\n%d\n%d\n", example1, example2, example3, example4, example5);
// }
