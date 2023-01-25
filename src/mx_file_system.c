#include "../inc/header.h"

void mx_file_system_go_until_symbol(t_string file_str, size_t *current_index, char c) {
    while (file_str[*current_index] != '\0') {
        (*current_index)++;
        if (file_str[(*current_index)] == c) {
            break;
        }
    }
}

int mx_file_system_get_number(t_string file_str, size_t *current_index) {
    mx_file_system_go_until_symbol(file_str, current_index, '\n');
    t_string number_str = mx_strndup(file_str, *current_index);
    size_t result = mx_atoi(number_str);
    free(number_str);
    return result;
}

int mx_file_system_get_weight(t_string file_str, size_t *current_index) {
    t_string weight_str = mx_file_system_get_island(file_str, current_index, '\n');
    int weight = mx_atoi(weight_str);
    free(weight_str);
    return weight;
}

t_string mx_file_system_get_island(t_string file_str, size_t *current_index, char delim) {
    size_t line_start = *current_index + 1;
    mx_file_system_go_until_symbol(file_str, current_index, delim);
    size_t island_size = *current_index - line_start;
    t_string island = mx_strndup(&file_str[line_start], island_size);
    return island;
}

t_bridge *mx_file_system_get_bridge(t_string file_str, size_t *current_index) {
    if (file_str == NULL || current_index == NULL) {
        return NULL;
    }
    t_bridge *bridge = (t_bridge *)malloc(sizeof(t_bridge));
    bridge->first = mx_file_system_get_island(file_str, current_index, '-');
    bridge->second = mx_file_system_get_island(file_str, current_index, ',');
    bridge->weight = mx_file_system_get_weight(file_str, current_index);
    return bridge;
}
