#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - Allocates memory using malloc and exits on failure.
 * @b: Number of bytes to allocate.
 *
 * Return: Pointer to the allocated memory.
 *         If malloc fails, the process terminates with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}

