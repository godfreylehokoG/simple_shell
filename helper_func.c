#include "shell.h"

/**
 * checkexit - replicates exits
 * @token: given command str
 * Return: returns entered errnum
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
 * __exit - free all allocated memory
 * @errnum: exit error number
 * @p: heap array of char pointers used to store commands
 * @getline: pointer to malloc space from getline function call
 * @head: head of linked list
 * @fc: pointer to allocated memory
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
 * linkedpath - creates a linked list path
 * Return: address of the list head.
 */

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

/**
 * findtensplaces - 
 * @i:
 * @s:
 * Return:
 */

int findtensplaces(int i, char *s)
{
	double tens = 1;

	while (s[i] >= '0' && s[i] <= '9')
	{
		tens *= 10;
		i++;
	}
	tens /= 10;
	return ((int) tens);
}
