#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
    if (*arr == NULL) 
        return;
    
    for (int i = 0; (*arr)[i] != NULL; i++) 
        mx_strdel(&(*arr)[i]);
    

    free(*arr);
    *arr = NULL;
}

// int main() {
//     char *arr[] = {"kakoi", "to", "text"};

//     printf("arr = {'kakoi', 'to', 'text'}\nmx_del_strarr(str) =>");

//     mx_del_strarr(&arr);

//     if (arr == NULL){
//         printf("arr (null):\n");
//     }

//     for (int i = 0; i < 3; i++) {
//         printf("\tarr[%d] = %s", i, arr[i]);
//     }
// }

