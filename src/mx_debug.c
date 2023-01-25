#include "../inc/header.h"

void mx_debug_print_str_arr(t_str_array *route) {
    if (route == NULL) {
        mx_printstr("NULL\n");
        return;
    }
    mx_printstr("{ ");
    for (size_t i = 0; i < route->SIZE; i++) {
        mx_printstr(route->array[i]);
        mx_printchar(' ');
    }
    mx_printstr("}");
}

void mx_debug_print_bridge(t_bridge bridge) {
    mx_printstr("{ '");
    mx_printstr(bridge.first);
    mx_printstr("', '");
    mx_printstr(bridge.second);
    mx_printstr("', ");
    mx_printint((int)bridge.weight);
    mx_printstr(" }");
}

void mx_debug_print_bridge_new_line(t_bridge bridge) {
    mx_debug_print_bridge(bridge);
    mx_printstr("\n");
}

void mx_debug_print_str_arr_until_str(t_str_array *strarray, t_string str) {
    if (strarray == NULL || str == NULL) {
        return;
    }
    mx_printstr("{ ");
    for (size_t i = 0; i < strarray->SIZE; i++) {
        if (mx_strcmp(strarray->array[i], str) == 0) {
            mx_printstr(str);
            mx_printstr(" }\n");
            return;
        }
        mx_printstr(strarray->array[i]);
        mx_printchar(' ');
    }
    mx_printchar('\n');
}

