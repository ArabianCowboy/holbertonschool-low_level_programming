#include "function_pointers.h"

/**
 * print_string - prints a C string using _putchar
 */
void print_string(const char *s)
{
	if (!s) return;
	while (*s)
		_putchar(*s++);
}

/**
 * _atoi - converts string to int (handles leading spaces and +/-)
 */
int _atoi(const char *s)
{
	int sign = 1, started = 0;
	long val = 0;

	if (!s) return 0;

	while (*s == ' ' || *s == '\t' || *s == '\n' ||
	       *s == '\r' || *s == '\f' || *s == '\v')
		s++;

	if (*s == '-' || *s == '+')
		sign = (*s++ == '-') ? -1 : 1;

	while (*s >= '0' && *s <= '9')
	{
		started = 1;
		val = val * 10 + (*s - '0');
		s++;
	}

	(void)started;
	return (int)(val * sign);
}

/**
 * print_number - prints an integer using _putchar
 */
void print_number(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		x = (unsigned int)(-n);
	}
	else
	{
		x = (unsigned int)n;
	}

	if (x / 10)
		print_number((int)(x / 10));

	_putchar((char)('0' + (x % 10)));
}
