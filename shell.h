#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

char _get_line(FILE *fp);
void errmessage(char **c, char *p, int i);
void _itoa(int i, char *t);

#endif
