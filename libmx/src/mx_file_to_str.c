#include "../inc/libmx.h"

int mx_get_file_size(const char *file) {
    char c;
    int size = 0;
    int fd = open(file, 0);

    if (fd == -1) {
        return -1;
    }

    while (read(fd, &c, 1)) {
        size++;
    }

    close(fd);

    return size;
}

char *mx_file_to_str(const char *file)
{
    char *result = NULL;
    char c;
    int fd = 0;
    int size = mx_get_file_size(file);

    if (size == -1) {
        return NULL;
    }

    fd = open(file, 0);

    if (fd == -1) {
        return NULL;
    }

    result = mx_strnew(size);

    for (int i = 0; i < size; i++) {
        read(fd, &c, 1);
        result[i] = c;
    }

    close(fd);

    return result;
}

// int main() {
//     char *buff = mx_file_to_str("../../../pathfinder/temp2/srdc/example.txt");
//     printf("'%s'", buff);
//     free(buff);
// }
