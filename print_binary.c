#include "main.h"

/**
 * int_binary - function to print binary
 *
 * @n: unsigned integer
 * @binary: character array to store binary string
 * @a: keep track of current position in binary string
 *
 */
void int_binary(unsigned int n, char *binary, int a)
{
	if (n == 0)
	{
		binary[a] = '\0';
	}
	else
	{
		binary[a] = (n & 1) ? '1' : '0';
		int_binary(n >> 1, binary, - 1);
	}
}
