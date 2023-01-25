#include "../inc/header.h"

void mx_free(t_string file_str, t_bridge_array *bridges, t_list *order_list) {
    free(file_str);
    for (size_t i = 0; i < bridges->SIZE; i++) {
        free(bridges->array[i]->first);
        free(bridges->array[i]->second);
        free(bridges->array[i]);
    }
    free(bridges->array);
    mx_clear_list(&order_list);
}

void mx_free_str_array(t_str_array *array) {
    if (array->array == NULL) {
        return;
    }
    for (size_t i = 0; i < array->SIZE; i++) {
        free(array->array[i]);
    }
    free(array->array);
    free(array);
}

void mx_free_everything(t_string file_str, t_string *order, t_list *transpositions, t_bridge_array *bridges) {
    mx_clear_bridges(bridges);
    mx_clear_list(&transpositions);
    free(order);
    free(file_str);
}
