#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc) {}
    char *agrv1_str = mx_file_to_str(argv[1]);
    char *agrv2_str = mx_file_to_str(argv[2]);
    (mx_strcmp(agrv1_str, agrv2_str) == 0) ? printf("true") : printf("false");
    free(agrv1_str);
    free(agrv2_str);
    return 0;
}
