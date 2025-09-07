#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int len = 0;
	int i;
	char temp;

	/* find length */
	while (s[len] != '\0')
		len++;

	/* swap chars from start and end */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
