#include "../inc/header.h"

void mx_printerr(t_string error) {
    if (error == NULL) {
        return;
    }
    write(2, error, mx_strlen(error));
}

void mx_error_system_usage(int argc) {
    if (argc != 2) { 
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}

void mx_error_system_file_does_not_exist(t_string file_str, t_string *argv) {
    if (file_str != NULL) {
        return;
    }
    mx_printerr("error: file ");
    mx_printerr(argv[1]);
    mx_printerr(" does not exist\n");
    free(file_str);
    exit(1);
}

void mx_error_system_file_is_empty(t_string file_str, t_string *argv) {
    if (mx_strcmp(file_str, "") != 0) {
        return;
    }
    mx_printerr("error: file ");
    mx_printerr(argv[1]);
    mx_printerr(" is empty\n");
    free(file_str);
    exit(1);
}

void mx_error_system_valid_number_ascii(t_string file_str) {
    if (mx_valid_number(file_str)) {
        return;
    }
    mx_printerr("error: line 1 is not valid\n");
    free(file_str);
    exit(1);
}

void mx_error_system_valid_number_value(t_string file_str, int SIZE) {
    if (SIZE > 0) {
        return;
    }
    mx_printerr("error: line 1 is not valid\n");
    free(file_str);
    exit(1);
}

void mx_error_system_invalid_input(t_string file_str) {
    size_t line_index = 1;
    if (mx_find_invalid_line(file_str, &line_index)) {
        return;
    }
    t_string line = mx_itoa(line_index);
    mx_printerr("error: line ");
    mx_printerr(line);
    mx_printerr(" is not valid\n");
    free(file_str);
    free(line);
    exit(1);
}

void mx_error_system_invalid_bridge_line(t_string file_str, t_bridge_array *bridges, t_list *order_list) {
    int valid_bridges = mx_valid_bridge_line(bridges);
    if (valid_bridges == -1) {
        return;
    }
    t_string line = mx_itoa(valid_bridges);
    mx_printerr("error: line ");
    mx_printerr(line);
    mx_printerr(" is not valid\n");
    mx_free(file_str, bridges, order_list);
    free(line);
    exit(1);
}

void mx_error_system_invalid_number_of_islands(t_string file_str, t_bridge_array *bridges, t_list *order_list, int SIZE) {
    if (mx_list_size(order_list) == SIZE) {
        return;
    }
    mx_printerr("error: invalid number of islands\n");
    mx_free(file_str, bridges, order_list);
    exit(1);
}

void mx_error_system_duplicate_bridges(t_string file_str, t_bridge_array *bridges, t_list *order_list) {
    if (!mx_has_duplicates(bridges)) {
        return;
    }
    mx_printerr("error: duplicate bridges\n");
    mx_free(file_str, bridges, order_list);
    exit(1);
}

void mx_error_system_sum_of_bridges_lengths_is_too_big(t_string file_str, t_bridge_array *bridges, t_list *order_list) {
    size_t size = 0;
    for (size_t i = 0; i < bridges->SIZE; i++) {
        size += bridges->array[i]->weight;
    }
    if (size < __INT_MAX__) {
        return;
    }
    mx_printerr("error: sum of bridges lengths is too big\n");
    mx_free(file_str, bridges, order_list);
    exit(1);
}
