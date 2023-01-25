#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list != NULL) {
        for (t_list *i = list; i; i = i->next) {
            for (t_list *j = list; j->next; j = j->next) {
                if (cmp(j->data, j->next->data)) {
                    //mx_swap(&j->data, &j->next->data);  
                    void *temporary = j->data;
                    j->data = j->next->data;
                    j->next->data = temporary;
                }
            }
        }
    }
    return list;
}

// bool cmp(void *first, void *second) {
//     return (mx_strcmp((char *)first, (char *)second) > 0);
// }

// int main() {
//     t_list *list = mx_create_node((void *)"O");

//     mx_push_back(&list, (void *)"A");
//     mx_push_back(&list, (void *)"F");
//     mx_push_back(&list, (void *)"Z");
//     mx_push_back(&list, (void *)"H");
//     mx_push_back(&list, (void *)"U");
//     mx_push_back(&list, (void *)"D");
//     mx_push_back(&list, (void *)"W");
//     mx_push_back(&list, (void *)"C");
//     mx_push_back(&list, (void *)"B");
//     mx_push_back(&list, (void *)"J");
//     mx_push_back(&list, (void *)"D");
//     mx_push_back(&list, (void *)"E");

//     mx_sort_list(list, cmp);

//     while (list != NULL) {
//         printf("list.data = %s\n", (char *)list->data);
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }
// }
