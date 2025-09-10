#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to scan
 * @accept: the set of accepted bytes
 *
 * Return: the number of bytes in the initial segment of @s
 *         which consist only of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;
	int hit;

	while (*s)
	{
		hit = 0;
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				hit = 1;
				break;
			}
		}
		if (!hit)
			break;
		count++;
		s++;
	}
	return (count);
}

