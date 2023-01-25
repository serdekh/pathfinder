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

char *mx_strstr(const char *s1, const char *s2) {
	int len = mx_strlen(s1);
	int substrlen = mx_strlen(s2);
	int start_pos = -1;
	
	if (s2 == NULL || s1 == NULL)
		return NULL;

	for (int i = 0; i < len; i++) {
	 	if (mx_strncmp(&s1[i], s2, substrlen) == 0) {
            start_pos = i;
            break;
        }
	}
	
	if (start_pos == -1) {
		return NULL;
	}
	
	return (char*)&s1[start_pos];
}

// #include <string.h>

// int main () {
//   const char haystack[23] = "iDontLikeProgrammingInC";
//   const char needle[10] = "T";
//   char *ret;

//   ret = strstr(haystack, needle);

//   printf("The substring is: %s\n", ret);

//   return(0);
// }
