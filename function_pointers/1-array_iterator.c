#include "function_pointers.h"

/**
 * array_iterator - executes a function on each array element
 * @array: int array
 * @size: number of elements
 * @action: function pointer applied to each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
