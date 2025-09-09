#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the resulting string
 */
char *leet(char *s)
{
	int i = 0, j;
	char from[] = "aAeEoOtTlL";
	char to[] =   "4433007711";

	while (s[i] != '\0')
	{
		for (j = 0; from[j] != '\0'; j++)
		{
			if (s[i] == from[j])
			{
				s[i] = to[j];
				break;
			}
		}
		i++;
	}
	return (s);
}

