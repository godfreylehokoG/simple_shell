#include "shell.h"

/**
 * main - checkout code
 * Return: 0
 */

int main (void)
{
	char *line = NULL;
	
	line = _getline(stdin, line);
	printf("%s\n", line);
	free(line);
	return (0);
}
