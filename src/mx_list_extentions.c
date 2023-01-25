#include "../inc/header.h"

void mx_pop_node(t_list **head, size_t index) {
    if (head == NULL || *head == NULL) {
        return;
    }
    if (index == 0) {
        mx_pop_front(head);
        return;
    }
    t_list *previous = NULL;
    size_t current_index = 0;
    for (t_list *t = *head; t != NULL; t = t->next) {
        if (current_index == index) {
            t_list *next_node = t->next;
            free(t);
            previous->next = next_node;
            return;
        }
        previous = t;
        current_index++;
    }
}

bool cmp(void *element1, void *element2) {
    if (element1 == NULL || element2 == NULL) {
        return false;
    }
    t_string first = mx_cast_array_to_str((t_str_array *)element1);
    t_string second = mx_cast_array_to_str((t_str_array *)element2);
    if (first == NULL || second == NULL) {
        return false;
    }
    bool result = (mx_strcmp(first, second) > 0);
    free(first);
    free(second);
    return result;
}

void mx_sort_str_arr_list(t_list *list) {
    if (list == NULL) {
        return;
    }
    mx_sort_list(list, cmp);
}

bool mx_is_str_uniqe(t_list *list, t_string str) {
    if (str == NULL) {
        return false;
    }
    if (list == NULL) {
        return true;
    }
    for (t_list *t = list; t != NULL; t = t->next) {
        if (mx_strcmp(str, (t_string)t->data) == 0) {
            return false;
        }
    }
    return true;
}

void mx_clear_list(t_list **list) {
    if (list == NULL) {
        return;
    }
    t_list *current = *list;
    while (current != NULL) {
        t_list *next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

