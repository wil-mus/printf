#include "main.h"
#include <ctype.h>

/**
 * gets_width - width to be printed
 *
 * @format: print the arguments of string formated
 * @a: argument list
 *
 * Return: width
 */

int gets_width(const char *format, int *a, va_list list)
{
	int b;
	int width = 0;

	for (b = *a + 1; format[b] != '\0'; b++)
	{
		if (is_digit(format[b]))
		{
			width *= 10;
			width += format[b] - '0';
		}
		else if (format[b] == '*')
		{
			b++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*a = b - 1;
	return (width);
}
