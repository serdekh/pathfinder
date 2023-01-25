#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);

    if (*list == NULL) {
        *list = node;
        return;
    }

    t_list *temporary = *list;

    while (temporary->next != NULL) {
        temporary = temporary->next;
    }

    temporary->next = node;
}

// int main(int argc, char *argv[]) {
//     t_list *list = NULL;

//     for (int i = 1; i < argc; i++) {
//         mx_push_back(&list, (void *)argv[i]);
//     }


//     if (list == NULL) {
//         printf("list == NULL");
//         return 0;
//     }

//     int count = 0;

//     while (list != NULL) {
//         printf("list[%d].data = %s\n", count, (char *)list->data);
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//         count++;
//     }   

//     return 0;
// }
