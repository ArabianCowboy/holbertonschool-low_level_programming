#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/* Provided by checker; don't push your own implementation */
int _putchar(char c);

/* Task 0 */
void print_name(char *name, void (*f)(char *));

/* Task 1 */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Task 2 */
int int_index(int *array, int size, int (*cmp)(int));

/* Calculator tasks (advanced) */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int (*get_op_func(char *s))(int, int);

/* Utils (no stdio) */
int _atoi(const char *s);
void print_number(int n);
void print_string(const char *s);

#endif /* FUNCTION_POINTERS_H */
