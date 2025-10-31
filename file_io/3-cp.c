#include "main.h"
#include <stdio.h>

/**
 * error_exit - prints an error message and exits with the given code
 * @code: exit code
 * @message: error message format
 * @arg: argument for message (usually filename or fd)
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, exits with codes 97, 98, 99, or 100 on errors
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rcount, wcount;
	char buffer[1024];
	mode_t mode = 0664;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((rcount = read(fd_from, buffer, 1024)) > 0)
	{
		wcount = write(fd_to, buffer, rcount);
		if (wcount == -1 || wcount != rcount)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (rcount == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", ""); /* handled below */

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
