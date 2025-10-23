#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Add or update an element in the hash table
 * @ht: The hash table
 * @key: The key (must not be an empty string)
 * @value: The value to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *new_node;
	char *key_copy, *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	/* Update value if key already exists */
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			char *new_val = strdup(value);
			if (new_val == NULL)
				return (0);
			free(node->value);
			node->value = new_val;
			return (1);
		}
		node = node->next;
	}

	/* Create new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	key_copy = strdup(key);
	value_copy = strdup(value);
	if (key_copy == NULL || value_copy == NULL)
	{
		free(new_node);
		free(key_copy);
		free(value_copy);
		return (0);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = ht->array[index]; /* Add at beginning for collision */
	ht->array[index] = new_node;

	return (1);
}
