#include "shell.h"

int main()
{
	char str[] = "Just testing this str";


	char* token = strtok(str, "-");

	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}
	return 0;
}
