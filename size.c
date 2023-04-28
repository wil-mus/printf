#include "main.h"

/**
 * gets_size - function that calculates size of cast
 *
 * @format: formated string to print arguments
 * @a: argument list printed
 *
 * Return: size
 */

int gets_size(const char *format, int *a)
{
	int size = 0;
	int b = *a + 1;

	if (format[b] == 'l')
		size = S_LONG;
	else if (format[b] == 'h')
		size = S_SHORT;
	if (size == 0)
		*a = b - 1;
	else
		*a = b;

	return (size);
}
