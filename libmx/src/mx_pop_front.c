#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    t_list *deleted = *head;
    *head = (*head)->next;
    free(deleted);
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
//     t_list *temp = list;

//     while (temp != NULL) {
//         printf("list[%d].data = '%s'\n", count, (char *)temp->data);
//         temp = temp->next;
//         count++;
//     }   

//     int removed = count + 1;

//     while (removed > count) {
//         printf("How much elements do you want to remove: ");
//         scanf("%d", &removed);
//     }

//     count = 0;
//     for (int i = 0; i < removed; i++) {
//         mx_pop_front(&list);
//         count++;
//     }   

//     if (list == NULL) {
//         printf("list == NULL\n");
//         return 0;
//     }

//     while (list != NULL) {
//         printf("list[%d].data = '%s'\n", count, (char *)list->data);
//         t_list *t = list;
//         list = list->next;
//         free(t);
//         count++;
//     }  

//     return 0;
// }
