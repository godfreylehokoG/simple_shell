#include "shell.h"

/**
 * _getline - feeds an entire line of input to the buffer
 * @fp: a single line of input
 * Return: the line of string from input
 */

char *_getline(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
