#ifndef MAIN_H
#define MAIN_H

#define SIZE BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/** FLAGS */
#define F_MINUS 0x01
#define F_PLUS 0x02
#define F_ZERO 0x04
#define F_HASH 0x08
#define F_SPACE 0x10

/** MACRO CONSTANT */
#define S_LONG 1
#define S_SHORT 2

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _putunsigned(unsigned int n);
int _putoctal(unsigned int n);
int _puthex(unsigned int n, int uppercase);
int get_precision(const char *format, int *a);
int get_flags(const char *format, int *a);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int convert_size_number(int n, int size);
int write_number(int is_negative, int i, char *buffer,
		const char *flags, int width, int precision, int size);

#endif
