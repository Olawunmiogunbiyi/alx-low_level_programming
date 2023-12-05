#include "hash_tables.h"

/**
 * key_index - returns the index of a key
 * @key: key to calculate index from
 * @size: of the array
 *
 * Return: an index to return to
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int my_index = 0;
	unsigned long int return_key = hash_djb2(key);

	my_index = return_key % size;

	return (my_index);
}
