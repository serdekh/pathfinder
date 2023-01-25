#include "../inc/header.h"

int main(int argc, char *argv[]) {
    mx_error_system_usage(argc);

    t_string file_str = mx_file_to_str(argv[1]);

    mx_error_system_file_does_not_exist(file_str, argv);
    mx_error_system_file_is_empty(file_str, argv);
    mx_error_system_valid_number_ascii(file_str);

    size_t file_str_current_index = 0;

    int SIZE = mx_file_system_get_number(file_str, &file_str_current_index);

    mx_error_system_valid_number_value(file_str, SIZE);
    mx_error_system_invalid_input(file_str);

    int BRIDGES_SIZE = mx_get_bridges_size(file_str);

    t_bridge **bridges = mx_init_bridges(BRIDGES_SIZE, file_str, &file_str_current_index);

    t_bridge_array bridges_array = {bridges, BRIDGES_SIZE};

    t_list *order_list = mx_create_order(&bridges_array);
    
    mx_error_system_invalid_bridge_line(file_str, &bridges_array, order_list);
    mx_error_system_invalid_number_of_islands(file_str, &bridges_array, order_list, SIZE);
    mx_error_system_duplicate_bridges(file_str, &bridges_array, order_list);
    mx_error_system_sum_of_bridges_lengths_is_too_big(file_str, &bridges_array, order_list);

    t_string *order = mx_init_order(&SIZE, order_list);

    t_list *transpositions = NULL;

    mx_start_algorithm(order, SIZE, transpositions, &bridges_array);
    mx_free_everything(file_str, order, transpositions, &bridges_array);

    return 0;
}
