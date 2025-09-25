#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison callback
 * @array: int array
 * @size: number of elements
 * @cmp: comparator returning non-zero when match found
 * Return: index of first match, -1 if none or invalid
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || !cmp || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
