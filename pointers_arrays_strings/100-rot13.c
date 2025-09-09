#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: pointer to the string to encode
 *
 * Return: pointer to the resulting string
 */
char *rot13(char *s)
{
	int i = 0, j;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[]   = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (s[i] != '\0')
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (s[i] == alpha[j])
			{
				s[i] = rot[j];
				break;
			}
		}
		i++;
	}
	return (s);
}

