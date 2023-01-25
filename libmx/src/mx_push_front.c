#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *first = malloc(sizeof(t_list));

    first->data = data;
    first->next = *list;

    *list = first;
}
