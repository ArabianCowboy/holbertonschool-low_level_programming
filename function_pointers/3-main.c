#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: program that takes 3 arguments:
 * num1 operator num2, and prints the result.
 * If the number of arguments is incorrect, print Error and exit 98.
 * If the operator is invalid, print Error and exit 99.
 * If user divides by 0, print Error and exit 100.
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (!op)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	result = op(num1, num2);

	printf("%d\n", result);
	return (0);
}
