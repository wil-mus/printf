#include "main.h"

/**
 * print_binary - function that prints integers in binary
 *
 * @args: argement list
 *
 * Return: no of characters printed
 */

int prints_binary(va_list args)
{
	int bit, printed_chars = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		n = -n;
	}
	if (n == 0)
	{
		_putchar('0');
		printed_chars++;
		return (printed_chars);
	}

	for (bit = (sizeof(int) * 8) - 1; bit >= 0; bit--)
	{
		if (n & (1 << bit))
		{
			_putchar('1');
			printed_chars++;
		}
		else if (printed_chars > 0)
		{
			_putchar('0');
			printed_chars++;
		}
	}

	return (printed_chars);
}
