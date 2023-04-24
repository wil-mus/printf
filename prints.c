#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>

/**
 * print_non_printable - prints ASCII codes
 *
 * @types: list of arguments
 * @buffer: array handling print
 * @flags: active flags
 * @width: width
 * @precision: specification of precision
 * @size: size
 *
 * Return: count
 */

int print_non_printable(va_list types, int flags,
		int width, int precision, int size)
{
	int a = 0;
	int count = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (printf("(null)"));
	while (s[a] != '\0')
	{
		if (isprint(s[a]))
		{
			count += printf("%c", s[a]);
		}
		else
		{
			count += printf("\\x%02x", s[a]);
		}
		a++;
	}
	return (count);
}

/**
 * print_reverse - prints strins in reverse
 *
 * Description: This is a function thet prints the strings in reverse
 *
 * Return: count
 */

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char *s;
	int a, count = 0;

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(precision);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		s = ")Null(";
	}
	count = strlen(s);

	for (a = count - 1; a >= 0; a--)
	{
		char z = s[a];
		write(1, &z, 1);
	}
	return (count);

}
