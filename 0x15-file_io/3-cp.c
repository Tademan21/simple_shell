#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * close_success_check - checks if close was successful
 * @c: return from close call
 * @fd: pointer to the fd
 */
void close_success_check(int c, int *fd)
{
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", *fd);
		exit(100);
	}
}

/**
 * error_exits - prints error messages and exits
 * @err: the error number to print
 * @fd1: first file descriptor to close
 * @fd2: second file descriptor to close
 * @fname: array of arguments
 */
void error_exits(int err, int *fd1, int *fd2, char *fname)
{
	int close_status;

	if (err == 988)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file ");
		dprintf(STDERR_FILENO, "%s\n", fname);
		exit(98);
	}

	if (err == 999)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fname);
		exit(99);
	}
	if (err == 98)
	{
		close_status = close(*fd1);
		close_success_check(close_status, fd1);
		close_status = close(*fd2);
		close_success_check(close_status, fd2);
		dprintf(STDERR_FILENO, "Error: Can't read from file ");
		dprintf(STDERR_FILENO, "%s\n", fname);
		exit(98);
	}

	if (err == 99)
	{
		close_status = close(*fd1);
		close_success_check(close_status, fd1);
		close_status = close(*fd2);
		close_success_check(close_status, fd2);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fname);
		exit(99);
	}
}

/**
 * read_chunk - reads a chunk from a file to a buffer string
 * @fd1: a pointer to the from file descriptor
 * @fd2: a pointer to the to file descriptor
 * @size: the maximum number of bytes to be read
 * @chunk: a pointer to a malloc'd empty string
 * @str: a pointer to the string with filename in case of error call
 * Return: a pointer to the string containing the read bytes
 */
size_t read_chunk(int *fd1, int *fd2, int size, char *chunk, char *str)
{
	int read_check;

	read_check = read(*fd1, chunk, size);

	if (read_check == -1)
	{
		free(chunk);
		error_exits(98, fd1, fd2, str);
	}

	return (read_check);
}

/**
 * write_chunk - writes a chunk from a buffer to a file
 * @fd1: a pointer to the from file descriptor
 * @fd2: a pointer to the to file descriptor
 * @size: the maximum number of bytes to be read
 * @chunk: a pointer to the buffer string to be written
 * @str: a pointer to the filename in case of error func call
 * Return: number of bytes written
 */
size_t write_chunk(int *fd1, int *fd2, int size, char *chunk, char *str)
{
	int write_size;

	if (chunk == NULL)
		error_exits(99, fd1, fd2, str);

	write_size = write(*fd2, chunk, size);

	if (write_size == -1)
	{
		free(chunk);
		error_exits(99, fd1, fd2, str);
	}

	return (write_size);
}

/**
 * main - copies the contents of one file to another
 * @argc: the number of arguments passed into the program
 * @argv: an array of the arguments passed in
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_s, write_s, close_check;
	char *chunk = NULL;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: cp file_from file_to\n", 28);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);

	if (fd_from == -1)
		error_exits(988, &fd_from, &fd_to, argv[1]);

	if (fd_to == -1)
		error_exits(999, &fd_from, &fd_to, argv[2]);

	write_s = 1024;
	while (write_s == 1024)
	{
		chunk = malloc(sizeof(*chunk) * 1024);

		if (chunk == NULL)
			error_exits(98, &fd_from, &fd_to, argv[1]);

		read_s = read_chunk(&fd_from, &fd_to, 1024, chunk, argv[1]);
		write_s = write_chunk(&fd_from, &fd_to, read_s, chunk, argv[2]);
		free(chunk);
	}

	close_check = close(fd_from);
	close_success_check(close_check, &fd_from);
	close_check = close(fd_to);
	close_success_check(close_check, &fd_to);

	return (0);
}
