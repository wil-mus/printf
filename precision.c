#include "main.h"

/**
 * gets_precision - calculate printing precision
 *
 * @format: formated string
 * @a: argument list to be printed
 * @list: íst
 *
 * Return: precision
 */

int gets_precision(const char *format, int *a, va_list list)
{
	int precision = -1;
	int c_i = *a + 1;

	precision = 1;

	if (format[c_i] != '.')
		return (precision);

	for (c_i += 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))
		{
			precision *= 10;
			precision += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*a = c_i - 1;

	return (precision);
}
