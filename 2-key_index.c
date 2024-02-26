#include "hash_tables.h"

/**
 * key_index - Get the index at which a key/value pair
 * should be stored in the array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 * Description: Uses the djb2 algorithm to calculate the index.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    /* Use the djb2 algorithm to calculate the hash and find the index */
	return (hash_djb2(key) % size);
}
