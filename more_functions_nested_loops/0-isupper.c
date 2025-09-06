#include "main.h"

/**
 * _isupper - Check if a character code is an uppercase letter (A–Z).
 * @c: ASCII code of the character to check.
 *
 * Return: 1 if uppercase, 0 otherwise.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
