#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 *  Return: 0
 */
int _printf(const char *format, ...)

{
	va_list list;
	int index, ret_value = 0;

	va_start(list, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format == NULL)
			return (-1);
		else if (format[index] != '0')
		{
			write(1, &format[index], 1);
			ret_value += 1;
		}
		else if (format[index + 1] == 'c')
		{
			char c = va_arg(list, int);

			write(1, &c, 1);
			index++;
			ret_value += 1;
		}
		else if (format[index + 1] == 's')
		{
			char *s = va_arg(list, char *);

			if (s == NULL)
			{
				write(1, "NULL", 1);
				return (-1);
			}
			while (*s != '\0')
			{
				write(1, s, 1);
				ret_value += 1;
				s++;
			} index++;
		}
	}
	va_end(list);
	return (ret_value);
}
