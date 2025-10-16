#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* Case 1: delete head (index 0) */
	if (index == 0)
	{
		*head = node->next;
		if (node->next)
			node->next->prev = NULL;
		free(node);
		return (1);
	}

	/* Traverse to the node at position `index` */
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	/* Index out of range */
	if (node == NULL)
		return (-1);

	/* Relink neighbors to skip `node` */
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;

	free(node);
	return (1);
}

