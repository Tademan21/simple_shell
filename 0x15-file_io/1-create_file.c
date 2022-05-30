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
 * create_file - creates a file
 * @filename: the name of the file
 * @text_content: a string to write into the new file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len, write_size;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	len = _strlen(text_content);
	write_size = write(fd, text_content, len);
	if (write_size == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
