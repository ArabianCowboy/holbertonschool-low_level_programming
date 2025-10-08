#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: address of pointer to the head node
 * @str: string to duplicate into the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tail;
	char *dup;
	size_t len = 0;

	if (head == NULL || str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	while (dup[len] != '\0')
		len++;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		free(dup);
		return (NULL);
	}

	node->str = dup;
	node->len = (unsigned int)len;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tail = *head;
	while (tail->next)
		tail = tail->next;

	tail->next = node;
	return (node);
}
