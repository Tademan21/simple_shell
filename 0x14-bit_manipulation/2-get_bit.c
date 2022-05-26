#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: integer memory location to be checked
 * @index: the bit position to be checked
 * Return: the value of the bit position or -1 for error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit;

	if (index > 31)
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}
