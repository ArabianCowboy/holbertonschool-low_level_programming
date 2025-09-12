#include "main.h"

/**
 * _factorial - returns the factorial of a given number
 * @n: number to calculate factorial for
 *
 * Return: factorial of n
 *         -1 if n is negative
 */
int _factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);

	return (n * _factorial(n - 1));
}
