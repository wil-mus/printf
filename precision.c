#include "main.h"
#include <stdarg.h>
#include <ctype.h>

/**
 * get_precision - calculate printing precision
 *
 * @format: formated string
 * @a: argument list to be printed
 *
 */

int get_precision(const char *format, int *a)
{
	int precision = -1;
	const char *c = format + *a + 1;
	va_list list;

	if (*c != '.')
	{
		return (precision);
	}
	c++;
	if (*c == '*')
	{
		precision = va_arg(list, int);
		*a = c - format;
		return (precision);
	}
	while (isdigit(*c))
	{
		precision *= 10;
		precision += (*c - '0');
		c++;
	}
	*a = c - format - 1;
	return (precision);
}
