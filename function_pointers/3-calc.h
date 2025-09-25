#ifndef CALC_H
#define CALC_H

#include "function_pointers.h"

/**
 * struct op - operator -> function mapping
 * @op: operator string
 * @f: function pointer
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

#endif /* CALC_H */
