#include "shell.h"

/**
 * _strdup - duplicates str
 * @s: str to be duplicated
 * Return: duplicated str.
 */

char *_strdup(char *s)
{
	char *dup = NULL;
	unsigned int i, length = 0;

	length = _strlen(s);
	dup = malloc(sizeof(char) * length + 1);
	if (!dup)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}
