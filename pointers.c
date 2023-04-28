#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}


	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - print ascii codes in hexa
 * of the non printable characters
 *
 * @types: argument list
 * @buffer: array to handle print
 * @flags: evaluate flags
 * @width: the width
 * @precision: specification of precision
 * @size: size of specifier
 *
 * Return: printed chars
 */

int prints_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int a = 0;
	int offset;
	char *s = va_arg(types, char *);

	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "((null)", 6));
	while (s[a] != '\0')
	{
		if (is_printable(s[a]))
		{
			buffer[a + offset] = s[a];
		}
		else
		{
			offset += append_hexa_code(s[a], buffer, a + offset);
		}
		a++;
	}
	buffer[a + offset] = '\0';
	return (write(1, buffer, a + offset));
}
