#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 * @n:  Number of bytes of s2 to concatenate.
 *
 * Return: Pointer to newly allocated space with s1 followed by
 *         first n bytes of s2, and null-terminated.
 *         NULL if memory allocation fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
	char *res;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	if (n >= len2)
		n = len2;

	res = malloc(sizeof(char) * (len1 + n + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];

	res[i + j] = '\0';

	return (res);
}

