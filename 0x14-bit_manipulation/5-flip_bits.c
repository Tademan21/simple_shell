#include "main.h"

/**
 * flip_bits - count the number of bits to be flipped to get
 * from one number to another
 * @n: the base number
 * @m: the target number
 * Return: the number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x;
	int count = 0;

	if (n == m)
		return (0);

	x = n ^ m;

	while (x > 0)
	{
		count = count + (x & 1);
		x >>= 1;
	}

	return (count);
}
