#include "shell.c"

int main()
{
	char source[] = "duplicate this string";

	char* target = strndup(source, 5);

	printf("%s", target);
	return 0;
}
