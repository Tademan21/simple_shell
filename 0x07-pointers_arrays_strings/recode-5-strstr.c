#include "main.h"

/**
 * match_finder - checks if a substring is present in a string
 * from the place the pointer is at
 * *h - the string to be examined
 * *s - the reference substring
 * Return: 1 if the string contains the substring, 0 if not.
 */
int match_finder(char *h, char *n)
{
	while (*n != '\0')
	{
		if (*n != *h)
			return (0);
		n++;
		h++;
	}
	return (1);
}

/**
 * _strstr - checks a given string for an exact match to a substring
 * @haystack: pointer the string to be checked
 * @needle: pointer to the reference substring
 * Return: a pointer to the start of the substring in the string, or null
 */
char *_strstr(char *haystack, char *needle)
{
	int match;

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			match = match_finder(haystack, needle);
				if (match == 1)
					return (haystack);
		}
		haystack++;
	}
	return (0);
}
