#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_error_and_exit - print error message to stderr and exit
 * @code: exit status
 * @fmt: printf-style format string
 * @arg: string argument (filename) or NULL
 *
 * Description: This helper always exits the program.
 */
static void print_error_and_exit(int code, const char *fmt, const char *arg)
{
	if (arg)
		dprintf(STDERR_FILENO, fmt, arg);
	else
		dprintf(STDERR_FILENO, "%s", fmt);
	exit(code);
}

/**
 * main - copy the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with codes:
 * 97 (usage), 98 (read error), 99 (write/create error), 100 (close error)
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t rcount, wcount;
	char buffer[1024];
	mode_t mode = 0664;

	if (argc != 3)
		print_error_and_exit(97,
			"Usage: cp file_from file_to\n", NULL);

	/* open source file */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(98,
			"Error: Can't read from file %s\n", argv[1]);

	/* open/create destination file */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit(99,
			"Error: Can't write to %s\n", argv[2]);
	}

	/* copy loop */
	while (1)
	{
		rcount = read(fd_from, buffer, 1024);
		if (rcount == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit(98,
				"Error: Can't read from file %s\n", argv[1]);
		}
		if (rcount == 0)
			break; /* EOF */

		wcount = write(fd_to, buffer, rcount);
		if (wcount == -1 || wcount != rcount)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit(99,
				"Error: Can't write to %s\n", argv[2]);
		}
	}

	/* close fds and handle close errors separately */
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
