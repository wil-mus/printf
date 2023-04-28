#include "main.h"

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

int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int a = 0;
	int count = 0;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
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
 * @types: the argument list
 * @buffer: print handling array
 * @flags: the active flags
 * @width: size of width
 * @precision: the precision
 * @size: size
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

	for (a = 0; s[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char z = s[a];

		write(1, &z, 1);
		count++;
	}
	return (count);

}
