#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>

#include "main.h"

/**
 * _strlen - counts the number of a chars in a null terminated string
 * @s: the string to be assessed
 * Return: number of chars or 0 if NULL or empty
 */
int _strlen(char *s)
{
	if (s == NULL)
		return (0);

	if (*s == '\0')
		return (0);

	s++;

	return (1 + _strlen(s));
}

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to a string containing the file name
 * @text_content: pointer to a string of text to be appended
 * Return: 1 for success or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_size, permission, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	permission = access(filename, W_OK);

	if (permission == -1)
	{
		close(fd);
		return (-1);
	}

	if (text_content == NULL)
		return (1);

	len = _strlen(text_content);
	write_size = write(fd, text_content, len);
	if (write_size == -1)
	{
		close(fd);
		return (-1);
	}
	return (1);
}
