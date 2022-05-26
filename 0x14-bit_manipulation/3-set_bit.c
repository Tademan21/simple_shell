#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the bytes to be altered
 * @index: the index to be used
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 31)
		return (-1);

	index = 1 << index;
	*n = *n | index;

	return (1);
}
