#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 * in lowercase, followed by a new line
 */
void print_alphabet_x10(void)
{
	int line;
	char c;

	for (line = 0; line < 10; line++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
	}
}
