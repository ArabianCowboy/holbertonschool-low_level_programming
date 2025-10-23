#include "hash_tables.h"
#include <string.h>

/**
 * create_node - Create a new hash node with duplicated key/value
 * @key: The key string
 * @value: The value string
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;
	char *key_copy, *value_copy;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	key_copy = strdup(key);
	value_copy = strdup(value);
	if (key_copy == NULL || value_copy == NULL)
	{
		free(new_node);
		free(key_copy);
		free(value_copy);
		return (NULL);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: Pointer to the hash table
 * @key: The key (must not be an empty string)
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

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

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
