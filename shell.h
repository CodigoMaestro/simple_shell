#ifndef GATES_OF_SHELL
#define GATES_OF_SHELL

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define BUFF_SIZE 12345
#define TRUE 1

int _strlen(const char *str);
char *_strpbrk(char *str, char *find);
char *_strtok(char *str, char *delim);
int _atoi(char *s);
void prompt_user(void);






















#endif
