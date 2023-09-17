#ifndef MAIN_H
#define MAIN_H

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


int _putchar(char c);
int _printf(const char *format, ...);
int int_to_string(int num, char *buffer, int bufferSize);
int decimal_to_binary(unsigned int num, int *count);
int decimal_to_HEX(unsigned int num, int *count);
int shell_env(char **env);
void execute_command(char *command, char **arguments, char **env);

/**
 * struct spec - Struct for format specifiers and their respective functions
 * @specifier: The format specifier
 * @func: The function associated with the format specifier
 *
 **/

typedef struct spec
{
	char specifier;
	void (*func)(va_list ap, int *count);
} spec;

void print_char(va_list ap, int *count);
void print_string(va_list ap, int *count);
void print_percent(va_list ap, int *count);
void print_integer(va_list ap, int *count);
void print_space(va_list ap, int *count);
void print_unsigned(va_list ap, int *count);
void print_hex(va_list ap, int *count);
void print_HEX(va_list ap, int *count);
void print_unsigned_octal(va_list ap, int *count);
void print_binary(va_list ap, int *count);
void print_nonprintable(va_list ap, int *count);


#endif
