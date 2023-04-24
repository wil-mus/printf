#include "main.h"

/**
 * get_size - function that calculates size of cast
 *
 * @format: formated string to print arguments
 * @a: argument list printed
 *
 * Return: size
 */

int get_size(const char *format, int *a)
{
	int size = 0;

	if (format[*a + 1] == 'l')
		size = S_LONG;
	else if (format[*a + 1] == 'h')
		size = S_SHORT;

	*a += (size > 0) ? 2 : 1;
	return (size);
}
