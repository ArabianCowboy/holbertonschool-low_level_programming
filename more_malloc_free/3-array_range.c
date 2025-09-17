#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers from min to max (inclusive).
 * @min: Starting integer.
 * @max: Ending integer.
 *
 * Return: Pointer to the newly created array,
 *         or NULL if min > max or on malloc failure.
 */
int *array_range(int min, int max)
{
	int *a;
	int len, i;

	if (min > max)
		return (NULL);

	len = max - min + 1;

	a = malloc(sizeof(int) * len);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		a[i] = min + i;

	return (a);
}

