#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to head of the list
 *
 * Description: frees each node's string (if any) then the node itself.
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str); /* safe even if str == NULL */
		free(head);
		head = tmp;
	}
}
