#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers starting with 1 and 2
 * Return: 0
 */
int main(void)
{
	int count;
	unsigned long a = 1, b = 2, next;

	printf("%lu, %lu", a, b);
	for (count = 3; count <= 50; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	printf("\n");
	return (0);
}

