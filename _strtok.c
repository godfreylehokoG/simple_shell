
#include "shell.h"

/**
 * _strtok - breaks str into tokens
 * @s: str to be broken into tokens
 * @delim: specifies delimiter to split the str by
 * Return: address of the next token.

char *_strtok(char *s, char *delim)
{
	static int spoint;
	int i = 0, x = 0;
	static int length;
	static char *copy;

	if (s != NULL)
	{
		length = _strlen(s);
		while (s[i] != '\0')
		{
			for (x = 0; delim[x] != '\0'; x++)
			{
				if (s[i] == delim[x])
						s[i] = '\0';
			}
			i++;
		}
		i = 0;
		while (s[i] == '\0' && i < length)
			i++;

		spoint = i;

		if (s[i] != '\0')
		{
			copy = s;
			return (s + i);
		}
		return (NULL);
	}
	else
	{
		i = spoint;
		s = copy;
		while (s[i] != '\0' && i < length)
			i++;
		while (s[i] == '\0' && i < length)
			i++;
		spoint = i;
		if (s[i] != '\0')
			return (s + i);
		return (NULL);
	}
}
