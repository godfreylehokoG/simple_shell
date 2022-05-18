#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first str to be compared
 * @s2: second str to be compared
 * Return: > 0 if s1 is positive < 0 if not.
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
