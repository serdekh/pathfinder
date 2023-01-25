#include "../inc/header.h"

t_bridge mx_new_bridge(char *first, char *second, size_t weight) {
    t_bridge bridge = {first, second, weight};
    return bridge;
}

t_bridge mx_new_empty_bridge() {
    return mx_new_bridge(NULL, NULL, 0);
}

bool mx_has_islands(char *island1, char *island2, t_bridge bridge) {
    return (
        (mx_strcmp(island1, bridge.first) == 0 && mx_strcmp(island2, bridge.second) == 0) ||
        (mx_strcmp(island2, bridge.first) == 0 && mx_strcmp(island1, bridge.second) == 0)
    );
}

bool mx_is_route_valid(t_str_array *route, t_bridge_array *bridges) {
    if (route == NULL || bridges == NULL) {
        return false;
    }
    for (size_t i = 1; i < route->SIZE; i++) {
        bool pair_exists = false;
        for (size_t j = 0; j < bridges->SIZE; j++) {
            if (mx_has_islands(route->array[i], route->array[i - 1], *(bridges->array[j]))) {
                pair_exists = true;
                break;
            }
        }
        if (!pair_exists) {
            return false;
        }
    }
    return true;
}

int mx_find_bridge_weight(t_bridge_array *bridges, t_string first, t_string second) {
    if (bridges == NULL || first == NULL || second == NULL) {
        return -1;
    }
    for (size_t i = 0; i < bridges->SIZE; i++) {
        if (mx_has_islands(first, second, *(bridges->array[i]))) {
            return (*(bridges->array[i])).weight;
        }
    }
    return -1;
}

size_t mx_get_route_distance(t_bridge_array *bridges, t_str_array *route) {
    if (bridges == NULL || route == NULL) {
        return 0;
    }
    size_t distance = 0;
    for (size_t i = 1; i < route->SIZE; i++) {
        distance += mx_find_bridge_weight(bridges, route->array[i], route->array[i - 1]);
    }
    return distance;
}

t_bridge **mx_init_bridges(const int BRIDGES_SIZE, t_string file_str, size_t *file_str_current_index) {
    if (file_str == NULL || file_str_current_index == NULL) {
        return NULL;
    }
    t_bridge **bridges = (t_bridge **)malloc(sizeof(t_bridge *) * BRIDGES_SIZE);
    for (int i = 0; i < BRIDGES_SIZE; i++) {
        bridges[i] = NULL;
    }
    for (int i = 0; i < BRIDGES_SIZE; i++) {
        t_bridge *bridge = mx_file_system_get_bridge(file_str, file_str_current_index);
        if (bridge != NULL) {
            bridges[i] = bridge;
        }
    }
    return bridges;
}

size_t mx_find_shortest_path(t_list *routes, t_bridge_array *bridges) {
    if (routes == NULL) {
        return 0;
    }
    size_t shortest_path = __INT_MAX__;
    for (t_list *t = routes; t != NULL; t = t->next) {
        t_str_array *temparr = (t_str_array *)t->data;
        size_t temparr_distance = mx_get_distance(temparr, bridges);
        if (temparr_distance < shortest_path) {
            shortest_path = temparr_distance;
        }
    }
    return shortest_path;
}

void mx_clear_bridge(t_bridge *bridge) {
    free(bridge->first);
    free(bridge->second);
    free(bridge);
}

int mx_get_bridges_size(t_string file_str) {
    int size = 0;
    int len = mx_strlen(file_str);
    for (int i = 0; i < len; i++) {
        if (file_str[i] == '\n' && file_str[i + 1] != '\0') {
            size++;
        }
    }
    return size;
}

bool mx_has_duplicates(t_bridge_array *bridges) {
    for (size_t i = 0; i < bridges->SIZE; i++) {
        t_bridge *temp = bridges->array[i];
        for (size_t j = i + 1; j < bridges->SIZE; j++) {
            if (mx_has_islands(temp->first, temp->second, *bridges->array[j])) {
                return true;
            }
        }
    }
    return false;
}

void mx_clear_bridges(t_bridge_array *bridges) {
    for (size_t i = 0; i < bridges->SIZE; i++) {
        mx_clear_bridge(bridges->array[i]);
    }
    free(bridges->array);
}

