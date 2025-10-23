#include "hash_tables.h"

/**
 * key_index - Get the index of a key in a hash table array
 * @key: The key to hash (non-NULL string)
 * @size: The size of the hash table array
 *
 * Return: The index at which the key/value should be stored
 *         (hash_djb2(key) % size). If size is 0, returns 0.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0)
		return (0);

	return (hash_djb2(key) % size);
}
