#include "function_pointers.h"

/**
 * print_name - calls a function on a provided name
 * @name: string
 * @f: function pointer that takes (char *)
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
