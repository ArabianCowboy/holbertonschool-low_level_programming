#include "main.h"

/**
 * sqrt_helper - helper to find natural square root recursively
 * @n: number to find square root of
 * @i: current guess
 *
 * Return: square root if found, otherwise -1
 */
int sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);

	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root of
 *
 * Return: natural square root, or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}
