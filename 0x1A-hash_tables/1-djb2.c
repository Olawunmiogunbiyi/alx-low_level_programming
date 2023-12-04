#include "hash_tables.h"
/*
 * hash_ djb2 algorithm = implementing the djb2algorithm
 * @str - the string to hash
 * return  the calculated hash
 */

unsigned long int hash_djb2(const unsigned char *str)
	{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
