#include "../inc/header.h"

bool mx_is_number(char c) {
    return (
        (c >= 48) && (c <= 57)
    );
}

bool mx_valid_number(t_string file_str) {
    for (size_t i = 0; file_str[i] != '\n'; i++) {
        if (!mx_is_number(file_str[i])) {
            return false;
        }
    }
    return true;
}

bool mx_valid_symbol(t_string file_str, char c, size_t valid_count, size_t start_index) {
    if (file_str[start_index] == c) {
        return false;
    }
    size_t count = 0;
    for (size_t i = start_index; file_str[i] != '\n'; i++) {
        if (file_str[i + 1] == '\0') {
            break;
        }
        if (file_str[i] == c) {
            count++;
        }
    }
    return (
        count == valid_count
    );
}

bool mx_valid_dash(t_string file_str, size_t start_index) {
    return mx_valid_symbol(file_str, '-', 1, start_index);
}

bool mx_valid_coma(t_string file_str, size_t start_index) {
    return mx_valid_symbol(file_str, ',', 1, start_index);
}

size_t mx_get_last_line(t_string file_str) {
    size_t line_index = 1;
    for (size_t i = 0; file_str[i] != '\0'; i++) {
        if (file_str[i] != '\n') {
            continue;
        }
        line_index++;
    }
    return line_index;
}

bool mx_find_invalid_line(t_string file_str, size_t *line_index) {
    for (size_t i = 0; file_str[i] != '\0'; i++) {
        if (file_str[i] != '\n') {
            continue;
        }
        (*line_index)++;
        size_t last = mx_get_last_line(file_str);
        if (last == (*line_index)) {
            return true;
        }
        bool valid_dash = mx_valid_dash(file_str, i + 1);
        bool valid_coma = mx_valid_coma(file_str, i + 1);
        size_t number_start_index = i;
        for (; file_str[number_start_index] != ',' && file_str[number_start_index + 1] != '\0'; number_start_index++) { }
        for (size_t j = number_start_index + 1; file_str[j] != '\n' && file_str[j + 1] != ' '; j++) {
            if (!mx_is_number(file_str[j])) {
                return false;
            }
        }
        if (valid_dash && valid_coma) {
            continue;
        }
        else {
            return false;
        }
        
    }
    return true;
}

int mx_valid_bridge_line(t_bridge_array *bridges) {
    for (size_t i = 0; i < bridges->SIZE; i++) {
        if (mx_strcmp(bridges->array[i]->first, bridges->array[i]->second) == 0) {
            return (i + 2); // i - index of the line in file, i + 1 - index of the line excluding first line with a number, i + 2 - bridge
        }
    }
    return -1;
}
