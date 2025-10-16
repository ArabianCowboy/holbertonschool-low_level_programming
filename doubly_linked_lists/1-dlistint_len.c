#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0; /* Step 1: start counting from 0 */

	/* Step 2: loop until we reach the end of the list */
	while (h != NULL)
	{
		count++;      /* Count the current node */
		h = h->next;  /* Move to the next node */
	}

	/* Step 3: return how many nodes we found */
	return (count);
}

