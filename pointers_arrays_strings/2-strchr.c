#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string to search
 * @c: character to find
 *
 * Return: pointer to the first occurrence of @c in @s,
 *         or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}

	/* If c is '\0', return pointer to the string terminator */
	if (c == '\0')
		return (s);

	return (0);
}

