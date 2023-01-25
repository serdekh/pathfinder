#pragma once

#include "../libmx/inc/libmx.h"

typedef char* t_string;

typedef struct s_bridge {
    t_string first;
    t_string second;
    size_t weight;
}              t_bridge;

typedef struct s_str_array {
    t_string *array;
    size_t SIZE;
}              t_str_array;

typedef struct s_bridge_array {
    t_bridge **array;
    size_t SIZE;
}              t_bridge_array;

/*
    debugging functions for printing: mx_debug_{function name}
*/

void mx_debug_print_bridge(t_bridge bridge); // prints bridges data to the standard output
void mx_debug_print_bridge_new_line(t_bridge bridge); // prints bridges and \n data to the standard output
void mx_debug_print_str_arr(t_str_array *array); // prints the array of strings to the standard output
void mx_debug_print_str_arr_until_str(t_str_array *strarray, t_string str); // prints the array of strings until the element int the array to the standard output

/*
    algorithm functions 
*/

void mx_swap(t_string *array, int i, int j); // swaps two elements in the array     
void mx_perm(t_str_array *array, t_bridge_array *bridges, t_string first, t_string last, t_list **transpositions); // main algorithm to find all transpositions in the array and add them to the list
void mx_print_route(t_str_array *route, t_bridge_array *bridges, t_string until); // prints route from one island to another one
void mx_start_algorithm(t_string *order, int SIZE, t_list *transpositions, t_bridge_array *bridges); // prints all the possible ways for each island in the order
void mx_sort_str_arr_list(t_list *list); // sorts list of t_str_array elements using mx_strcmp() function
void mx_print_route_from_to(t_string from, t_string to, t_list *transpositions, t_string *order, int SIZE, t_bridge_array *_bridges); // print route from one island to another using mx_perm() function
size_t mx_get_distance(t_str_array *route, t_bridge_array *bridges); // gets sum of distances between bridges

t_list *mx_create_order(t_bridge_array *bridges); // creates a list of strings that contain uniqe character is the "first appear" order

t_string mx_cast_array_to_str(t_str_array *array); // concatinates all string in the array to a single one. This is required for the mx_sort_str_arr_list() function

t_string *mx_dupstrarr(t_string *source_array, const size_t SIZE); // returns an allocated duplicate of array of string 
t_string *mx_init_order(int *SIZE, t_list *order_list); // turns the list of unqige strings into an array and returns a pointer to it

/*
    bridges functions
*/

int mx_get_bridges_size(t_string file_str); // sums all the lengths of bridges in file
int mx_find_bridge_weight(t_bridge_array *bridges, t_string first, t_string second); // goes for each element in bridges and finds the correct one by input islands. Return a weight of found one

bool mx_has_islands(char *island1, char *island2, t_bridge bridge); // does bridge has both of islands?
bool mx_has_duplicates(t_bridge_array *bridges); // does bridge array contain duplicates&?
bool mx_is_route_valid(t_str_array *route, t_bridge_array *bridges); // does the array of string match the bridges connection in file?

void mx_clear_bridge(t_bridge *bridge); // frees an allocated bridge
void mx_clear_bridges(t_bridge_array *bridges); // frees an array of allocated bridges

size_t mx_get_route_distance(t_bridge_array *bridges, t_str_array *route); // finds sum of route's weights 
size_t mx_find_shortest_path(t_list *routes, t_bridge_array *bridges); // finds the route with a minimum sum of weights

t_bridge mx_new_empty_bridge(); // creates a bridge with empty data {null, null, 0}
t_bridge mx_new_bridge(char *first, char *second, size_t weight); // creates a bridge with a given input

t_bridge **mx_init_bridges(const int BRIDGES_SIZE, t_string file_str, size_t *file_str_current_index); // creates an array of bridges by reading them from the file

/*
    file system functions: mx_file_system_{function name}
*/

int mx_file_system_get_number(t_string file_str, size_t *current_index); // reads a number in line from current index

t_bridge *mx_file_system_get_bridge(t_string file_str, size_t *current_index); // reads a line in file and returns a bridge

t_string mx_file_system_get_island(t_string file_str, size_t *current_index, char delim); // reads an island in file until it finds a character delim

/*
    error system
*/

void mx_printerr(t_string error); // prints a message to the stderr
void mx_error_system_usage(int argc); // prints error if invalid number of arguments
void mx_error_system_file_is_empty(t_string file_str, t_string *argv); // prints error if given file is empty
void mx_error_system_invalid_input(t_string file_str); // prints error if one of the lines is invalid
void mx_error_system_duplicate_bridges(t_string file_str, t_bridge_array *bridges, t_list *order_list); // prints error if a duplicate bridge was found
void mx_error_system_valid_number_ascii(t_string file_str); // prints error if number is invalid written (4f or sd6)
void mx_error_system_valid_number_value(t_string file_str, int SIZE); // print error if number value is less or equal to zero
void mx_error_system_invalid_bridge_line(t_string file_str, t_bridge_array *bridges, t_list *order_list); // prints error if there is an invalid bridge in file
void mx_error_system_file_does_not_exist(t_string file_str, t_string *argv); // prints error if file does not exist
void mx_error_system_invalid_number_of_islands(t_string file_str, t_bridge_array *bridges, t_list *order_list, int SIZE); // print error if number in the brgging of the file doesn't match the real count
void mx_error_system_sum_of_bridges_lengths_is_too_big(t_string file_str, t_bridge_array *bridges, t_list *order_list); // prints error if sum of bridges weight is bigger than INT_MAX

/*
    list functions
*/

void mx_clear_list(t_list **list); // frees list
void mx_pop_node(t_list **head, size_t index); // removes an element in the list by its index

bool mx_is_str_uniqe(t_list *list, t_string str); // boolean function used in mx_sort_str_arr_list() one

/*
    file validation
*/

int mx_valid_bridge_line(t_bridge_array *bridges); // checks is bridge an array valid

bool mx_is_number(char c); // check if char is a number using ascii table
bool mx_valid_number(t_string file_str); // check if number is the beggining of the file is valid
bool mx_valid_dash(t_string file_str, size_t start_index); // checks if '-' characters in a line  valid written
bool mx_valid_coma(t_string file_str, size_t start_index); // checks if ',' characters in a line  valid written
bool mx_find_invalid_line(t_string file_str, size_t *line_index); // checks if one of the file lines is invalid
bool mx_valid_symbol(t_string file_str, char c, size_t valid_count, size_t start_index); // checks if characters count in a line valid

/*
    memory management
*/

void mx_free(t_string file_str, t_bridge_array *bridges, t_list *order_list); // frees the input data
void mx_free_str_array(t_str_array *array); // frees allocated string array
void mx_free_everything(t_string file_str, t_string *order, t_list *transpositions, t_bridge_array *bridges); // frees everything allocated at the end of program
