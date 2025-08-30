#include <stdio.h>

/**
 * main - prints sum of even Fibonacci numbers not exceeding 4,000,000
 * Return: 0
 */
int main(void)
{
	unsigned long a = 1, b = 2, next, sum = 0;

	while (b <= 4000000)
	{
		if ((b % 2) == 0)
			sum += b;
		next = a + b;
		a = b;
		b = next;
	}
	printf("%lu\n", sum);
	return (0);
}

