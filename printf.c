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
	int flag_plus = 0;
	int flag_space = 0;
	int flag_hash = 0;

	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
				{
					flag_plus = 1;
				}
				else if (*format == ' ')
				{
					flag_space = 1;
				}
				else if (*format == '#')
				{
					flag_hash = 1;
				}
			}
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					{

						if (flag_plus)
						{
							_putchar('+');
							printed_chars++;
						}
						else if (flag_space)
						{
							_putchar(' ');
							printed_chars++;
						}
					}
					printed_chars += write(1, va_arg(args, char *), 0);
					break;
				case 'S':
					{
						char *s = va_arg(args, char *);
						if (flag_plus)
						{
							_putchar('+');
							printed_chars++;
						}
						else if (flag_space)
						{
							_putchar(' ');
							printed_chars++;
						}
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
					{
						if (flag_plus)
						{
							_putchar('+');
							printed_chars++;
						}
						else if (flag_space)
						{
							_putchar(' ');
							printed_chars++;
						}
					}
					printed_chars += _putunsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					if (flag_hash)
					{
						_putchar('0');
						printed_chars++;
					}
					printed_chars += _putoctal(va_arg(args, unsigned int));
					break;
				case 'x':
					if (flag_hash)
					{
						_putchar('0');
						_putchar('x');
						printed_chars += 2;
					}
					printed_chars += _puthex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					if (flag_hash)
					{
						_putchar('0');
						_putchar('X');
						printed_chars += 2;
					}
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
