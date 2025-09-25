#include "function_pointers.h"

/* write-only helpers */
static void _err(const char *s)
{
	print_string(s);
}

int op_add(int a, int b) { return (a + b); }
int op_sub(int a, int b) { return (a - b); }
int op_mul(int a, int b) { return (a * b); }

int op_div(int a, int b)
{
	if (b == 0)
	{
		_err("Error\n");
		/* Holberton convention: exit code 100 on div by zero */
		exit(100);
	}
	return (a / b);
}

int op_mod(int a, int b)
{
	if (b == 0)
	{
		_err("Error\n");
		exit(100);
	}
	return (a % b);
}
