#include "main.h"

/**
 * _isdigit - Check if a character code is a digit (0–9).
 * @c: ASCII code of the character to check.
 *
 * Return: 1 if digit, 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

