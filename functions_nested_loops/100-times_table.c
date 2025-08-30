#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the table size (0..15)
 */
void print_times_table(int n)
{
	int r, c, p;

	if (n < 0 || n > 15)
		return;

	for (r = 0; r <= n; r++)
	{
		for (c = 0; c <= n; c++)
		{
			p = r * c;

			if (c == 0)
				_putchar('0');
			else
			{
				_putchar(',');
				_putchar(' ');
				if (p < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar('0' + p);
				}
				else if (p < 100)
				{
					_putchar(' ');
					_putchar('0' + (p / 10));
					_putchar('0' + (p % 10));
				}
				else
				{
					_putchar('0' + (p / 100));
					_putchar('0' + ((p / 10) % 10));
					_putchar('0' + (p % 10));
				}
			}
		}
		_putchar('\n');
	}
}

