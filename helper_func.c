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

/**
 * checkexit - implements exit builtin and exits with supplied error #
 * @token: user command strings
 * Return: If user entered exit, returns entered errnum
 */

int checkexit(char **token)
{
	char check[] = "exit";
	int errnumber = 0;

	if (_strcmp(token[0], check) == 0)
	{
		if (token[1])
		{
			errnumber = _atoi(token[1]);
		}
		if (errnumber == -1)
			return (2);
		else
			return (errnumber);
	}
	return (-1);
}

/**
 * __exit - gracefully exits by freeing all malloced memory
 * @errnum: exits with this error number
 * @p: heap array of char pointers used to store comands
 * @getline: pointer to malloc space from getline function call
 * @head: head of linked list
 * @fc: malloced string path/to/file from PATH function
 * @predirect: malloc string of previous directory
 */

void __exit(int errnum, char **p, char *getline, PDIRECT *head, char *fc, char *predirect)
{
	PDIRECT *tmp;

	if (p)
		free(p);
	if (getline)
		free(getline);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	if (fc)
		free(fc);
	if (predirect)
		free(predirect);
	exit(errnum);
}

/**
 *  * linkedpath - builds a linked list of the PATH
 *   * Return: pointer to head of the linked list
 *    */
PDIRECT *linkedpath(void)
{
	char *path, *token = NULL, *delim = ":";
	PDIRECT *head, *temp, *temp2;

	head = malloc(sizeof(PDIRECT));
	if (!head)
		return (NULL);
	head->next = NULL;

	path = _strdup(_getenv("PATH"));

	token = _strtok(path, delim);
	head->s = token;

	temp = head;
	while (token != NULL)
	{
		token = _strtok(NULL, delim);
		if (token != NULL)
		{
			temp2 = malloc(sizeof(PDIRECT));
			temp2->s = token;
			temp2->next = NULL;
			temp->next = temp2;
			temp = temp2;
		}
	}
	return (head);
}

