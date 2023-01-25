#pragma once

#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>

#ifdef __APPLE__
#include <malloc/malloc.h>
#endif //__APPLE__

#ifdef __linux
#include <malloc.h>
#define malloc_size malloc_usable_size
#endif //__linux__

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

int mx_atoi(const char *str);

/*
 * utils pack funcs (14)
 */

void mx_printchar(char c);                                             // SUCCESS
void mx_print_unicode(wchar_t c);                                      // FAIL
void mx_printstr(const char *s);                                       // SUCCESS
void mx_print_strarr(char **arr, const char *delim);                   // FAIL (DONE)
void mx_printint(int n);                                               // SUCCESS
double mx_pow(double n, unsigned int pow);                             // SUCCESS
int mx_sqrt(int x);                                                    // SUCCESS
char *mx_nbr_to_hex(unsigned long nbr);                                // SUCCESS
unsigned long mx_hex_to_nbr(const char *hex);                          // SUCCESS
char *mx_itoa(int number);                                             // SUCCESS [80/100]
void mx_foreach(int *arr, int size, void (*f)(int));                   // SUCCESS
int mx_binary_search(char **arr, int size, const char *s, int *count); // FAIL
int mx_bubble_sort(char **arr, int size);                              // SUCCESS
int mx_quicksort(char **arr, int left, int right);                     // FAIL (DONE)

/*
 * string pack funcs (24)
*/

int mx_strlen(const char *s);                                                   // SUCCESS
void mx_swap_char(char *s1, char *s2);                                          // SUCCESS
void mx_str_reverse(char *s);                                                   // SUCCESS [80/100] (DONE)
void mx_strdel(char **s);                                                       // SUCCESS
void mx_del_strarr(char ***arr);                                                // SUCCESS
int mx_get_char_index(const char *str, char c);                                 // SUCCESS
char *mx_strdup(const char *s1);                                                // FAIL (DONE)
char *mx_strndup(const char *s1, size_t n);                                     // FAIL (DONE)
char *mx_strcpy(char *dst, const char *src);                                    // SUCCESS
char *mx_strncpy(char *dst, const char *src, int len);                          // SUCCESS
int mx_strcmp(const char *s1, const char *s2);                                  // SUCCESS
char *mx_strcat(char *restrict s1, char *restrict s2);                          // FAIL (DONE)
char *mx_strstr(const char *haystack, const char *needle);                      // SUCCESS
int mx_get_substr_index(const char *str, const char *sub);                      // SUCCESS
int mx_count_substr(const char *str, const char *sub);                          // FAIL (DONE)
int mx_count_words(const char *str, char c);                                    // SUCCESS
char *mx_strnew(const int size);                                                // SUCCESS [65/100] (DONE)
char *mx_strtrim(const char *str);                                              // FAIL (DONE)
char *mx_del_extra_spaces(const char *str);                                     // FAIL (DONE)
char **mx_strsplit(const char *s, char c);                                      // FAIL
char *mx_strjoin(const char *s1, const char *s2);                               // SUCCESS [50/100]
char *mx_file_to_str(const char *file);                                         // FAIL (DONE)
char *mx_replace_substr(const char *str, const char *sub, const char *replace); // FAIL (DONE BAD)
int mx_read_line(char **lineptr, size_t buf_sizem, char delim, const int fd);   // FAIL

/*
 * memory pack funcs (9)
*/

void *mx_memset(void *b, int c, size_t len);                                             // SUCCESS
void *mx_memcpy(void * restrict dst, const void * restrict src, size_t n);               // SUCCESS
void *mx_memccpy(void * restrict dst, const void * restrict src, int c, size_t n);       // SUCCESS
int mx_memcmp(const void *s1, const void *s2, size_t n);                                 // SUCCESS
void *mx_memchr(const void *s, int c, size_t n);                                         // SUCCESS
void *mx_memrchr(const void *s, int c, size_t n);                                        // SUCCESS 
void *mx_memmem(const void* big, size_t big_len, const void *little, size_t little_len); // SUCCESS [95/100]
void *mx_memmove(void *dst, const void *src, size_t len);                                // SUCCESS                        
void *mx_realloc(void *ptr, size_t size);                                                // SUCCESS [70/100]

/*
 * list pack funcs (7)
*/

t_list *mx_create_node(void *data);                          // SUCCESS
void mx_push_front(t_list **list, void *data);               // SUCCESS
void mx_push_back(t_list **list, void *data);                // FAIL (DONE)
void mx_pop_front(t_list **head);                            // FAIL (DONE)
void mx_pop_back(t_list **head);                             // FAIL (DONE)
int mx_list_size(t_list *list);                              // FAIL (DONE)
t_list *mx_sort_list(t_list *lst, bool(*cmp)(void*, void*)); // FAIL (DONE)

//
// MAX SCORE = 54 * 100 = 5400
// CURRENT SCORE = 29 * 100 + 80 * 2 + 65 + 50 + 95 + 70 = 3340
// RESULT = CURRENT SCORE / MAX SCORE = 62%
