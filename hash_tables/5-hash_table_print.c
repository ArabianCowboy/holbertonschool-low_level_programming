#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Print all key/value pairs in the hash table
 * @ht: The hash table to print
 *
 * Description: Prints in the format:
 * {'key1': 'value1', 'key2': 'value2', ...}
 * Order: array index order, then linked list order.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
			node = node->next;
		}
	}
	printf("}\n");
}
