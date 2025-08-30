#include <stdio.h>

/*
 * We split each Fibonacci number into high and low parts:
 *   x = x_high * 10^9 + x_low, where 0 <= x_low < 10^9
 * This keeps arithmetic in 64-bit range while printing full values.
 */

/**
 * main - prints the first 98 Fibonacci numbers starting with 1 and 2
 * Return: 0
 */
int main(void)
{
	int i;
	unsigned long a_high = 0, a_low = 1; /* 1 */
	unsigned long b_high = 0, b_low = 2; /* 2 */
	unsigned long next_high, next_low;
	const unsigned long BASE = 1000000000UL;

	printf("%lu, %lu", a_low, b_low);

	for (i = 3; i <= 98; i++)
	{
		/* next = a + b (split by BASE) */
		next_low = a_low + b_low;
		next_high = a_high + b_high;

		if (next_low >= BASE)
		{
			next_low -= BASE;
			next_high += 1;
		}

		/* print next */
		if (next_high == 0)
			printf(", %lu", next_low);
		else
			printf(", %lu%09lu", next_high, next_low);

		/* shift window */
		a_high = b_high;
		a_low = b_low;
		b_high = next_high;
		b_low = next_low;
	}
	printf("\n");
	return (0);
}

