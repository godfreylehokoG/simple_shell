#include "shell.h"

/**
 * _itoa - converts int to 
 * @i: int to be converted to str
 * @t: address to the converted str
 * Return: void fuction.

void _itoa(int i, char *t)
{
	int j;
	int rem = 0;
	int counter = 0;
	char temp;

	if (i == 0)
	{
		t[0] = '0';
		t[1] = '\0';
	}

	while (i != 0)
	{
		rem = i % 10;
		t[counter++] = rem + '0';
		i = i / 10;
	}

	for (j = 0; j < counter / 2; j++)
	{
		temp = t[j];
		t[j] = t[counter - 1 - j];
		t[counter - 1 - j] = temp;
	}

	t[counter] = '\0';

}
