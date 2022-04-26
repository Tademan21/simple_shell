#include "main.h"

/**
 * _memset - fills the first n bytes of a memory area with a constant byte
 * @s: the pointer to the memory area to be filled
 * @b: the pointer to the constant byte to be used
 * @n: the number of bytes at s to be filled
 * Return: a pointer (s) to the filled memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while (idx < n)
	{
		s[idx] = b;
		idx++;
	}
	return (s);
}
