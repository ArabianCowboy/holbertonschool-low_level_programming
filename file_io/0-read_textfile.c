#include "main.h"

/**
 * read_textfile - reads a text file and prints it
 *                 to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of bytes to read and print
 *
 * Return: actual number of bytes printed,
 *         or 0 on any error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount;
	ssize_t wcount;
	char *buffer;

	if (filename == NULL || letters == 0)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	rcount = read(fd, buffer, letters);
	if (rcount == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	wcount = write(STDOUT_FILENO, buffer, rcount);
	if (wcount == -1 || wcount != rcount)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (wcount);
}

