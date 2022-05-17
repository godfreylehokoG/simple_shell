
#include "shell.h"

char *_strtok(char *s, char *delim)
{
	static int spoint;
	int i = 0, x = 0;
	static int length;
	static char *copy;

	if (s != NULL)
	{
		length = _strlen(s);
		while (s[i] != '\0') /** replaces delim with null byte*/
		{
			for (x = 0; delim[x] != '\0'; x++)
			{
				if (s[i] == delim[x])
						s[i] = '\0';
			}
			i++;
		}
		i = 0;
		while (s[i] == '\0' && i < length) /** removes leading null bytes*/
			i++;

		spoint = i; /**spoint is now start of string */

		if (s[i] != '\0')
		{
			copy = s; /** makes string static */
			return (s + i); /** return start of string */
		}
		return (NULL);
	}
	else
	{
		i = spoint;
		s = copy;
		while (s[i] != '\0' && i < length) /**goes through characters */
			i++;
		while (s[i] == '\0' && i < length) /**goes through null bytes */
			i++;
		spoint = i;
		if (s[i] != '\0')
			return (s + i);
		return (NULL);
	}
}
