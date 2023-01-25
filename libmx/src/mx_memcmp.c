#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *str1 = (unsigned char *)s1;
    unsigned char *str2 = (unsigned char *)s2;

    if (s1 == NULL || s2 == NULL || n <= 0) {
		return 0;
    }

	for (size_t i = 0; i < n; i++) {
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		if (str1[i] == '\0' && str2[i] == '\0')
			return 0;
	}

	return 0;
}

// #include <stdio.h>
// #include <string.h>

// void test_get_str_input(char *text, char *s) {
//     printf("%s: ", text);
//     scanf("%s", s);
//     printf("\n");
// }

// int main () {
//     char str1[30];
//     char str2[30];
//     int n = 0;
    
//     while (true) {
//         test_get_str_input("str1", str1);
//         test_get_str_input("str2", str2);

//         printf("n: ");
//         scanf("%d", &n);
//         printf("\n");

//         int resmx = mx_memcmp(str1, str2, n);
//         int res = memcmp(str1, str2, n);

//         printf("\n\tmx_memcmp: %d\n", resmx);
//         printf("\n\t   memcmp: %d\n\n", res);
        
//         (resmx - res == 0) 
//             ? printf("\n\tPERFECT!\n\n")
//             : printf("\n\tFAILURE!\n\n");      
//     }
    
//     return(0);
// }
