#include "hash_tables.h"

/**
 * hash_table_create - Create a new hash table
 * @size: Number of buckets (array size)
 *
 * Return: Pointer to newly created hash_table_t on success, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(*ht));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(*(ht->array)));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	return (ht);
}
