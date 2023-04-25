#include "main.h"

/**
 * print_rot13 - Print string in rot 13
 *
 * @types: argument list
 * @buffer: array to handle buffer
 * @flags: active flags
 * @width: width
 * @precision: specification of precision
 * @size: size
 *
 * Return: count
 */

int print_rot13(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c;
	char *s;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);

	if (s == NULL)
		s = "( )";

	for (a = 0; s[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == s[a])
			{
				c = out[b];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			c = s[a];
			write(1, &c, 1);
			count++;
		}
	}

	return (count);
}
