#include "hash_tables.h"

/**
 * hash_table_set - function to set key/value of a hash table
 * @ht: pointer to a Hash table data structure
 * @key: key of the index to update
 * @value: value to updat in Hash table
 *
 * Return: 1 on Success or 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *temp;
	hash_node_t *new_node;

	index = key_index((const unsigned char *)key, ht->size);

	if (strcmp(key, "") == 0)
		return (0);
	if (!ht || !key)
		return (0);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
