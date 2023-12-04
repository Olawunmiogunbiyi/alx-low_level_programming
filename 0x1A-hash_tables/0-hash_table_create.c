/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created table, otherwise NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
    unsigned long int i;

    hash_table_t *my_table = malloc(sizeof(hash_table_t));

    if (my_table == NULL)
        return NULL;

    my_table->size = size;

    my_table->array = malloc(sizeof(hash_node_t *) * size);

    if (my_table->array == NULL)
    {
        free(my_table);
        return NULL;
    }

    for (i = 0; i < size; i++)
    {
        my_table->array[i] = NULL;
    }

    return my_table;
}

