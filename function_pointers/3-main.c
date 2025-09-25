#include "function_pointers.h"

/**
 * main - simple calculator using function pointers
 * @argc: count
 * @argv: vector [num1, op, num2]
 * Return: 0 on success, exits with 98/99/100 on error
 */
int main(int argc, char **argv)
{
	int a, b, res;
	int (*op)(int, int);

	if (argc != 4)
	{
		print_string("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (!op)
	{
		print_string("Error\n");
		exit(99);
	}

	a = _atoi(argv[1]);
	b = _atoi(argv[3]);
	res = op(a, b);

	print_number(res);
	_putchar('\n');
	return (0);
}
