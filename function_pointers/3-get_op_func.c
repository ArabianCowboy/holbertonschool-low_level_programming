#include "function_pointers.h"
#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator string ("+", "-", "*", "/", "%")
 * Return: pointer to the corresponding function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add}, {"-", op_sub}, {"*", op_mul},
		{"/", op_div}, {"%", op_mod}, {NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (s && s[0] == ops[i].op[0] && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
