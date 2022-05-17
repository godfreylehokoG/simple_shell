#include "shell.h"

int tokencount(char *s)
{
	int tokencounter = 0;
	int i = 0;

	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] == '\0' || s[i] == '\n')
		return (0);

	while (s[i] != '\0')
	{
		tokencounter++;
		while (s[i] != ' ' && s[i] != '\0')/** goes through all characters */
			i++;

		while (s[i] == ' ' && s[i] != '\0') /** goes through all spaces */
			i++;


	}
	return (tokencounter);
}
