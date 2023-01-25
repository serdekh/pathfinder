#include "../inc/header.h"

void mx_swap(t_string *array, int i, int j) {
    if (array == NULL || i < 0 || j < 0) {
        return;
    }
    t_string t = array[i];
    array[i] = array[j];
    array[j] = t;
}

void mx_printchar_until(char c, size_t count, bool newline_start, bool newline_end) {
    if (newline_start) {
        mx_printchar('\n');
    }
    for (size_t i = 0; i < count; i++) {
        mx_printchar(c);
    }
    if (newline_end) {
        mx_printchar('\n');
    }
}

void mx_print_route(t_str_array *route, t_bridge_array *bridges, t_string until) {
    if (route == NULL || bridges == NULL || until == NULL) {
        return;
    }
    size_t distance = 0;
    //mx_printstr("========================================\n");
    mx_printchar_until('=', 40, false, true);
    mx_printstr("Path: ");
    mx_printstr(route->array[0]);
    mx_printstr(" -> ");
    mx_printstr(route->array[route->SIZE - 1]);
    mx_printchar('\n');
    mx_printstr("Route: ");
    for (size_t i = 0; i < route->SIZE - 1; i++) {
        if (mx_strcmp(route->array[i], until) != 0) {
            mx_printstr(route->array[i]);
            mx_printstr(" -> ");
        }
    }
    mx_printstr(route->array[route->SIZE - 1]);
    mx_printchar('\n');
    mx_printstr("Distance: ");
    for (size_t i = 1; i < route->SIZE - 1; i++) {
        if (mx_strcmp(route->array[i], until) != 0) {
            int weight = mx_find_bridge_weight(bridges, route->array[i], route->array[i - 1]);
            if (weight != -1) {
                mx_printint(weight);
                mx_printstr(" + ");
                distance += weight;
            }
        }
    }
    int weight = mx_find_bridge_weight(bridges, route->array[route->SIZE - 1], route->array[route->SIZE - 2]);
    if (weight != -1) {
        distance += weight;
        mx_printint(weight);
        if ((int)distance == weight) {
            //mx_printstr("\n========================================\n");
            mx_printchar_until('=', 40, true, true);
            return;
        }
        mx_printstr(" = ");
        mx_printint(distance);
        mx_printchar('\n');
    }
    //mx_printstr("========================================\n");
    mx_printchar_until('=', 40, false, true);
}

t_string mx_cast_array_to_str(t_str_array *array) {
    if (array == NULL) {
        return NULL;
    }
    int result_strlen = 0;
    for (size_t i = 0; i < array->SIZE; i++) {
        result_strlen += mx_strlen(array->array[i]);
    }
    t_string result = mx_strnew(result_strlen);
    int j = 0;
    for (size_t i = 0; i < array->SIZE; i++) {
        for (int k = 0; k < mx_strlen(array->array[i]); k++) {
            result[j] = array->array[i][k];
            j++;
        }
    }
    return result;
}

bool mx_is_str_array_copy(t_list *transpositions, t_str_array *array) {
    for (t_list *t = transpositions; t != NULL; t = t->next) {
        t_str_array *temparr = (t_str_array *)t->data;
        if (array->SIZE == temparr->SIZE) {
            bool equal = true;
            for (size_t i = 0; i < array->SIZE; i++) {
                if (mx_strcmp(array->array[i], temparr->array[i]) != 0) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                return true;
            }
        }
    }
    return false;
}

t_string *mx_dupstrarr(t_string *source_array, const size_t SIZE) {
    t_string *allocated = (t_string *)malloc(sizeof(t_string) * SIZE);
    for (size_t i = 0; i < SIZE; i++) {
        allocated[i] = mx_strdup(source_array[i]);
    }
    return allocated;
}

t_list *mx_create_order(t_bridge_array *bridges) {
    if (bridges == NULL) {
        return NULL;
    }
    t_list *uniqes = NULL;
    for (size_t i = 0; i < bridges->SIZE; i++) {
        t_string first = bridges->array[i]->first;
        t_string second = bridges->array[i]->second;
        if (mx_is_str_uniqe(uniqes, first)) {
            mx_push_back(&uniqes, first);
        }
        if (mx_is_str_uniqe(uniqes, second)) {
            mx_push_back(&uniqes, second);
        }
    }
    return uniqes;
}


t_string *mx_init_order(int *SIZE, t_list *order_list) {
    *SIZE = mx_list_size(order_list);

    t_string *order = (t_string *)malloc(sizeof(t_string) * (*SIZE));
    int index = 0;

    for (t_list *t = order_list; t != NULL; t = t->next) {
        order[index] = (t_string)t->data;
        index++;
    }
    mx_clear_list(&order_list);
    return order;
}

size_t mx_get_distance(t_str_array *route, t_bridge_array *bridges) {
    if (route == NULL || bridges == NULL || route->array == NULL || bridges->array == NULL) {
        return 0;
    }
    size_t distance = 0;
    for (size_t i = 1; i < route->SIZE; i++) {
        for (size_t j = 0; j < bridges->SIZE; j++) {
            if (mx_has_islands(route->array[i], route->array[i - 1], *bridges->array[j])) {
                distance += bridges->array[j]->weight;
                break;
            }
        }
    }
    return distance;
}

t_str_array mx_cut_array(t_str_array *array, t_string until) {
    int until_index = -1;
    for (size_t i = 0; i < array->SIZE; i++) {
        if (mx_strcmp(until, array->array[i]) == 0) {
            until_index = (int)i;
            break;
        }
    }
    if (until_index == -1) {
        t_string *copy = (t_string *)malloc(sizeof(t_string));
        for (size_t i = 0; i < array->SIZE; i++) {
            copy[i] = mx_strdup(array->array[i]);
        }
        t_str_array copy_str_array = {copy, array->SIZE};
        return copy_str_array;
    }
    t_string *cut_str = (t_string *)malloc(sizeof(t_string) * (until_index + 1));
    for (int i = 0; i <= until_index; i++) {
        cut_str[i] = mx_strdup(array->array[i]);
    }
    t_str_array result = {cut_str, until_index + 1};
    return result;
}

void mx_try_add_array_to_transpositions(t_str_array *array, t_bridge_array *bridges, t_string first, t_string last, t_list **transpositions) {
    if (mx_strcmp(array->array[0], first) != 0) {
        return;
    }
    t_str_array *cut = (t_str_array *)malloc(sizeof(t_str_array));
    *cut = mx_cut_array(array, last);
    (mx_is_route_valid(cut, bridges) && !mx_is_str_array_copy(*transpositions, cut))
        ? mx_push_back(transpositions, cut)
        : mx_free_str_array(cut);
}

int mx_get_index_of_order(t_string str, t_str_array *order) {
    for (int i = 0; i < (int)order->SIZE; i++) {
        if (mx_strcmp(order->array[i], str) == 0) {
            return i;
        }
    }
    return -1;
}

bool compare_strs(t_str_array *first, t_str_array *second, t_str_array *order) {
    if (order == NULL || first == NULL || second == NULL) {
        return false;
    }
    size_t firstsize = first->SIZE;
    size_t secondsize = second->SIZE;
    size_t size = (firstsize > secondsize) ? secondsize : firstsize;
    for (size_t i = 0; i < size; i++) {
        int firsti = mx_get_index_of_order(first->array[i], order);
        int secondi = mx_get_index_of_order(second->array[i], order);
        if (firsti == -1 || secondi == -1) {
            continue;
        }
        if (firsti < secondi) {
            return false;
        }
    }
    return true;
}

t_list *mx_sort_str_array_list(t_list *list, t_str_array *order, bool (*cmp)(t_str_array *a, t_str_array *b, t_str_array *c)) {
    if (list == NULL) {
        return list;
    }

    for (t_list *i = list; i != NULL; i = i->next) {
        for (t_list *j = list; j->next != NULL; j = j->next) {
            if (cmp(j->data, j->next->data, order)) {
                t_str_array *temporary = j->data;
                j->data = j->next->data;
                j->next->data = temporary;
            }
        }
    }
    return list;
}

void mx_perm(t_str_array *array, t_bridge_array *bridges, t_string first, t_string last, t_list **transpositions) {
    if (array == NULL || bridges == NULL || first == NULL || last == NULL || (mx_strcmp(first, array->array[array->SIZE - 1]) == 0)) {
        return;
    }
    const size_t N = array->SIZE;
    size_t indexes[N];
    t_string *order_dup = mx_dupstrarr(array->array, array->SIZE);
    t_str_array _order_dup = {order_dup, array->SIZE};
    for (size_t j = 0; j < N; j++) {
        indexes[j] = j;
    }
    size_t i = 0;
    while (i < N) {
        if (indexes[i] != 0) {
            indexes[i]--;
        }
        size_t j = i & 1 ? indexes[i] : 0;
        mx_swap(array->array, i, j);
        mx_try_add_array_to_transpositions(array, bridges, first, last, transpositions);
        i = 1;
        while (indexes[i] == 0) {
            indexes[i] = i;
            i++;
        }
    }
    mx_sort_str_array_list(*transpositions, &_order_dup, compare_strs);
     for (size_t i = 0 ; i < array->SIZE; i++) {
        free(order_dup[i]);
    }
    free(order_dup);
}

void mx_print_route_from_to(t_string from, t_string to, t_list *transpositions, t_string *order, int SIZE, t_bridge_array *_bridges) {
    if (from == NULL || to == NULL || order == NULL || _bridges == NULL) {
        return;
    }
    if (mx_strcmp(from, to) == 0) {
        return;
    }
    t_string *order_dup = mx_dupstrarr(order, SIZE);
    t_str_array _order_dup = {order_dup, SIZE};
    mx_perm(&_order_dup, _bridges, from, to, &transpositions);
    size_t shortest_path = mx_find_shortest_path(transpositions, _bridges);
    size_t routes_size = mx_list_size(transpositions);
    for (size_t i = 0; i < routes_size; i++) {
        size_t index = 0;
        for (t_list *t = transpositions; t != NULL; t = t->next) {         
            size_t distance = mx_get_distance((t_str_array *)t->data, _bridges);
            if (distance != shortest_path) {
                mx_free_str_array((t_str_array *)t->data);
                mx_pop_node(&transpositions, index);
                break;
            }
            index++;
        }
    }
    //mx_sort_str_arr_list(transpositions);
    for (t_list *t = transpositions; t != NULL; t = t->next) {
        t_str_array *array = (t_str_array *)t->data;
        mx_print_route(array, _bridges, to);
        mx_free_str_array(array);
    }
    mx_clear_list(&transpositions);
    for (int i = 0 ; i < SIZE; i++) {
        free(order_dup[i]);
    }
    free(order_dup);
}

void mx_start_algorithm(t_string *order, int SIZE, t_list *transpositions, t_bridge_array *bridges) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            mx_print_route_from_to(order[i], order[j], transpositions, order, SIZE, bridges);
        }
    } 
}
