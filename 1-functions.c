#include "main.h"

/**
  * is_printable - function that evaluates if a char is printable
  *
  * @c: char evaluated
  *
  * Return: 1 if c is printable, else 0
  */

int is_printable(char c)
{
	return (c >= 32 && c < 127);
}

/**
  * append_hexa_code - Append ascii in hexadecimal code to buffer
  * 
  * @buffer: array of chars
  * @i: index at which to start appending
  * @ascii_code: ASCII CODE
  *
  * Return: 3
  */

int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[a++] = '\\';
	buffer[a++] = 'x';
	buffer[a++] = map_to[ascii_code / 16];
	buffer[a] = map_to[ascii_code % 16];
	return (3);
}

/**
  * is_digit - function that verifies if a char is a digit
  * 
  * @c: Char evaluated
  *
  * Return: 1 if c is a digit, 0 otherwise
  */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
  * convert_size_number - Casts a number to the specified size
  *
  * @num: Number casted
  * @size: Number indicator of number type to be casted.
  *
  * Return: casted value
  */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
  * convert_size_unsgnd - Casts a number to the specified size
  *
  * @num: Number casted
  * @size: indicator of number type to be casted.
  *
  * Return: Casted value
  */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);

}
