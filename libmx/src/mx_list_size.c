#include "../inc/libmx.h" 

int mx_list_size(t_list *list) {
    int length = 0;

    for (t_list *node = list; node != NULL; node = node->next) {
        length++;
    }

    return length;
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

//     printf("List size: %d\n", mx_list_size(list));

//     while (list != NULL) {
//         printf("list[%d].data = %s\n", count, (char *)list->data);
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//         count++;
//     }   


//     return 0;
// }
