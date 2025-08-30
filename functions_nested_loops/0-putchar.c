#include "main.h"

/**
 * main - Entry point; prints "_putchar" followed by a newline
 * Return: 0 on success
 */
int main(void)
{
	char s[] = "_putchar\n";
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (0);
}
