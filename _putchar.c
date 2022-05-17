#include "shell.h"

/**
 * _putchar - prints a char
 * @c: char to be printed
 * Return: 0 if successful 1 if not.
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
