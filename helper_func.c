#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: 
 * @s2: 
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (-1);
}


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
