#include "shell.h"

/**
 * findcommand - searches for file in path
 * @head: pointer to the linked list of the path
 * @commandinput: command to check in path
 * Return: address to command in in path if found, or null if not.
 */

char *findcommand(PDIRECT *head, char *commandinput)
{

	char *buf;
	int commandinputlen = 0, dirlen = 0, i, j;


	commandinputlen = _strlen(commandinput);
	while (head != NULL)
	{
		dirlen = _strlen(head->s);

		buf = malloc(sizeof(char) * (commandinputlen + dirlen) + 2);
		if (!buf)
			return (NULL);

		for (i = 0; i < dirlen; i++)
		{
			buf[i] = (head->s)[i];
		}
		buf[i++] = '/';
		for (j = 0; j < commandinputlen; j++)
		{
			buf[j + i] = commandinput[j];
		}
		buf[j + i] = '\0';

		if (access(buf, X_OK) == 0)
		{
			return (buf);

		}

		free(buf);
		head = head->next;
	}

	return (NULL);
}
