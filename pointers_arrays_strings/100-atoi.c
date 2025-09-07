#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Description: Skips any non-digit characters until the first digit.
 * Handles multiple '-' signs before digits (odd count => negative).
 * Parsing stops at the first non-digit after digits start.
 *
 * Return: the integer value parsed from the string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			/* flip sign for each '-' seen before digits */
			if (!started)
				sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = (num * 10) + (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	return ((int)(num * sign));
}
