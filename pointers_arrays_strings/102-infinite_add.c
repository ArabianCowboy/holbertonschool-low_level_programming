#include "main.h"

/**
 * infinite_add - adds two positive numbers stored as strings
 * @n1: first number (as string)
 * @n2: second number (as string)
 * @r: buffer to store the result
 * @size_r: size of buffer r
 *
 * Return: pointer to result r, or 0 if it cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, carry = 0, d1, d2, sum;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	/* k is index where we place the null-terminator (end of string) */
	k = size_r - 1;
	r[k] = '\0';
	k--;

	i--;
	j--;

	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
			return (0);

		d1 = (i >= 0) ? n1[i] - '0' : 0;
		d2 = (j >= 0) ? n2[j] - '0' : 0;
		if (d1 < 0 || d1 > 9 || d2 < 0 || d2 > 9)
			return (0);

		sum = d1 + d2 + carry;
		r[k] = (sum % 10) + '0';
		carry = sum / 10;

		i--;
		j--;
		k--;
	}

	/* shift result to the start of buffer if needed */
	k++;
	return (r + k);
}

