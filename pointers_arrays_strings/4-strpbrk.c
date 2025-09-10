#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to scan
 * @accept: the set of bytes to look for
 *
 * Return: pointer to the first byte in @s that matches any byte in @accept,
 *         or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
				return (s);
		}
		s++;
	}
	return (0);
}

