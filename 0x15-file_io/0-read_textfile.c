#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <unistd.h>

#include "main.h"

/**
 * read_textfile - reads a text file to stdout
 * @filename: a pointer to a string containing the file name
 * @letters: the number of letters to be read and printed
 * Return: number of letters read and printed or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, written, read_size;
	char *buff;

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buff = malloc(sizeof(*buff) * (letters + 1));

	if (buff == NULL)
	{
		close(fd);
		return (0);
	}

	read_size = read(fd, buff, letters);
	if (read_size == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}

	close(fd);
	buff[letters] = '\0';
	written = write(STDOUT_FILENO, buff, read_size);
	free(buff);

	if (written == -1 || written < read_size)
	{
		free(buff);
		close(fd);
		return (0);
	}
	return (written);
}
