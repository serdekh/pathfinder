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

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if (str == NULL || sub == NULL || replace == NULL) {
		return NULL;
    }
    const int subs = mx_count_substr(str, sub);
    const int sublen = mx_strlen(sub);
    const int strlen = mx_strlen(str);
    const int replacelen = mx_strlen(replace);
	const int resultlen = strlen + subs * (replacelen - sublen);

    if (strlen <= sublen) {
		return NULL;
    }

	char *result = mx_strnew(resultlen);

	for (int i = 0; i < resultlen; i++) {
        if (!mx_strncmp((char *)str, (char *)sub, sublen)) {
            str += sublen;

            for (int j = 0; j < replacelen; j++) {
                result[i] = replace[j];
                i++;
            }
        }

        result[i] = *str;
        str++;
    }

    return result;
}

// void TEST_print_replaced(char *str, char *sub, char *replaced) {
//     char *result = mx_replace_substr(str, sub, replaced);
//     printf("%s\n", result);
//     free(result);
// }

// int main() {
//     TEST_print_replaced("McDonalds", "alds", "uts");
//     TEST_print_replaced("Ururu turu", "ru", "ta");
// }
