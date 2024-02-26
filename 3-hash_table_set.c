#include "hash_tables.h"

hash_node_t *create_new_node(const char *key, const char *value);

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: Hash table
 * @key: Key to be added (cannot be an empty string)
 * @value: Value associated with the key (can be an empty string)
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	hash_node_t *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	if (node == NULL)
	{
		new_node = create_new_node(key, value);
		if (new_node == NULL)
			return (0);

		ht->array[index] = new_node;
		return (1);
	}

	/* If key exists, replace value */
	while (node != NULL)
	{
		if (strcmp(key, node->key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}

	/* If key doesn't exist, create a new node */
	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * create_new_node - Creates a new node.
 * @key: Key for the new node (cannot be an empty string)
 * @value: Value associated with the key (can be an empty string)
 * Return: Pointer to the new node on success, NULL on failure
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}
