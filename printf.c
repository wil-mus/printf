#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf- output of the produce according to format
 *
 * @format: character string
 * @...: The optional arguments
 *
 * Return: no of characters printed
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += write(1, va_arg(args, char *), 0);
					break;
				case 'S':
					{
						char *s = va_arg(args, char *);
						while (*s != '\0')
						{
							if (*s < ' ' || *s >= 127)
							{
								printed_chars += write(1, "\\x", 2);
								printed_chars += _puthex(*s, 1);
							}
							else
							{
								_putchar(*s);
								printed_chars++;
							}
							s++;
						}
						break;
					}
				case 'u':
					printed_chars += _putunsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					printed_chars += _putoctal(va_arg(args, unsigned int));
					break;
				case 'x':
					printed_chars += _puthex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					printed_chars += _puthex(va_arg(args, unsigned int), 1);
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
