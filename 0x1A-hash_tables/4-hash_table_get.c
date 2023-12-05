#include "hash_tables.h"

/**
 * hash_table_get - function to get a value from a hash table
 * @ht: pointer to a Hash table data structure
 * @key: key of the index to update
 *
 * Return: the value at an index of a hash table
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *temp;

	if (!ht || !key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	if (strcmp(key, "") == 0)
		return (NULL);

	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}

	return (NULL);
}
