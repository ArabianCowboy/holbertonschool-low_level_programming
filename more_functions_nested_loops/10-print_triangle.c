#include "main.h"

/**
 * print_triangle - Prints a triangle using the character '#'.
 * @size: The size of the triangle.
 */
void print_triangle(int size)
{
	int row, space, hash;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (row = 1; row <= size; row++)
		{
			for (space = 0; space < (size - row); space++)
				_putchar(' ');
			for (hash = 0; hash < row; hash++)
				_putchar('#');
			_putchar('\n');
		}
	}
}

