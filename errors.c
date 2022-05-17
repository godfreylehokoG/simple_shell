#include "shell.h"

void errmessage(char **c, char *p, int i)
{
	char *t;

	t = malloc(sizeof(char) * i);
	_itoa(i, t);
	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, t, _strlen(t));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, c[0], _strlen(c[0]));
	write(STDOUT_FILENO, ": not found\n", 12);

	free(t);
}

void CDerrmessage(char **c, char *p, int i)
{
	char *t;

	t = malloc(sizeof(char) * i);
	_itoa(i, t);
	write(STDOUT_FILENO, p, _strlen(p));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, t, _strlen(t));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, c[0], _strlen(c[0]));
	write(STDOUT_FILENO, ": can't cd to ", 14);
	write(STDOUT_FILENO, c[1], _strlen(c[1]));
	write(STDOUT_FILENO, "\n", 1);

	free(t);
}
