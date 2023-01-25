#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if (s1 == NULL && s2 != NULL) {
        return (char *)s1;
    }
    if (s1 != NULL && s2 == NULL) {
        return (char *)s1;
    }

    int len = mx_strlen(s1) + mx_strlen(s2);
    char *joined = mx_strnew(len);

    joined = mx_strcat(joined, (char *)s1);
    joined = mx_strcat(joined, (char *)s2);

    return joined;
}

// int main() {
//     char *str1 = "this";
//     char *str2 = "dodge ";
//     char *str3 = NULL;

//     char *joined1 = mx_strjoin(str2, str1);
//     char *joined2 = mx_strjoin(str1, str3);
//     char *joined3 = mx_strjoin(str3, str3);

//     printf("'%s'\n'%s'\n'%s'", joined1, joined2, joined3);

//     //free(joined1);
//     //free(joined2);
//     //free(joined3);

//     return 0;
// }
