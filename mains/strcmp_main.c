#include "../shell.h"

int main()
{
	char *X = "Techie";
	char *Y = "Tech";

	int ret = _strcmp(X, Y);

	if (ret > 0) {
		printf("%s", "X is greater than Y");
	}
	else if (ret < 0) {
		printf("%s", "X is less than Y");
	}
	else {
		printf("%s", "X is equal to Y");
	}

	return 0;
}
