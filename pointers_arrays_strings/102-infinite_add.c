#include "main.h"

/**
 * infinite_add - adds two positive numbers stored as strings
 * @n1: first number (as string)
 * @n2: second number (as string)
 * @r: buffer to store the result (result must start at r[0])
 * @size_r: size of buffer r (including '\0')
 *
 * Return: pointer to r on success, or 0 if it cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, write, carry = 0, d1, d2, sum;
	int start, end, idx;

	if (size_r < 2)
		return (0);

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	/* end is index of final '\0'; write is last digit position */
	end = size_r - 1;
	r[end] = '\0';
	write = end - 1;

	i--;
	j--;

	while (i >= 0 || j >= 0 || carry)
	{
		if (write < 0)
			return (0);

		d1 = (i >= 0) ? n1[i] - '0' : 0;
		d2 = (j >= 0) ? n2[j] - '0' : 0;

		/* reject non-digits (inputs must be positive integers) */
		if ((i >= 0 && (d1 < 0 || d1 > 9)) ||
		    (j >= 0 && (d2 < 0 || d2 > 9)))
			return (0);

		sum = d1 + d2 + carry;
		r[write] = (sum % 10) + '0';
		carry = sum / 10;

		i--;
		j--;
		write--;
	}

	/* shift result to r[0].. */
	start = write + 1;
	idx = 0;
	while (r[start] != '\0')
	{
		r[idx++] = r[start++];
	}
	r[idx] = '\0';

	return (r);
}

