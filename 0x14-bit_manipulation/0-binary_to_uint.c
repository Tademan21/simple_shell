#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a string of ones and zeros to
 * the unsigned int equivalent
 * @b: the string to be converted
 * Return: unsigned int equivalent of binary string, or 0 if
 * string is empty or string contains chars other than 1 or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n, idx;

	if (b == NULL)
		return (0);

	idx = 0;
	n = 0;
	while (b[idx] != '\0')
	{
		if (b[idx] != '0' && b[idx] != '1')
			return (0);
		n <<= 1;
		n = n + b[idx] - '0';
		idx++;
	}

	return (n);
}
