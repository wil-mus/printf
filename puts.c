#include "main.h"
#include <unistd.h>

/**
 * _putoctal - prints unsigned octal format
 *
 * @n: unsigned int printed
 *
 * Return: no of printed digits
 */

int _putoctal(unsigned int n)
{
	int digit = 0;
	char octal[32];
	int a;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	for (a = 0; n > 0; a++)
	{
		octal[a] = (n % 8) + '0';
		n /= 8;
	}
	for (a = a - 1; a >= 0; a--)
	{
		_putchar(octal[a]);
		digit++;
	}
	return (digit);
}

/**
 * _puthex - prints unsigned int in the hexadecimal format
 *
 * @n: unsigned int to be printed
 * @uppercase: if it is set to 1 print uppercase
 *
 * Return: no of digits
 */

int _puthex(unsigned int n, int uppercase)
{
	int digit = 0;
	int a;
	int remainder;
	char hex[32];
	char c;

	if (n == 0)
	{
		_putchar('0');
		digit++;
	}
	while (n != 0)
	{
		remainder = n % 16;

		if (remainder < 10)
		{
			c = remainder + '0';
		}
		else
		{
			if (uppercase)
			{
				c = remainder - 10 + 'A';
			}
			else
			{
				c = remainder - 10 + 'a';
			}
		}
		hex[digit] = c;
		digit++;

		n /= 16;
	}
	for (a = digit - 1; a >= 0; a--)
	{
		_putchar(hex[a]);
	}
	return (digit);
}

/**
 * _putunsigned - printts int
 *
 * @n: int to be printed
 *
 * Return: digits printed
 */

int _putunsigned(unsigned int n)
{
	unsigned int digits = 0;

	if (n / 10)
		digits += _putunsigned (n / 10);
	_putchar((n % 10) + '0');
	digits++;

	return (digits);
}
