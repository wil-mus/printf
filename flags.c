#include "main.h"
#include <string.h>

/**
 * gets_flags - active flags to be calculated
 *
 * @format: strings in which arguments are printed
 * @a: function paramater
 *
 * RReturn: flags
 */

int gets_flags(const char *format, int *a)
{
	int flags = 0;
	const char *c = format + *a + 1;

	while (*c && strchr("-+0# ", *c))
	{
		switch (*c)
		{
			case '-':
				flags |= F_MINUS;
				break;
			case '+':
				flags |= F_PLUS;
				break;
			case '0':
				flags |= F_ZERO;
				break;
			case '#':
				flags |= F_HASH;
				break;
			case ' ':
				flags |= F_SPACE;
				break;
		}
		c++;
	}
	*a = c - format - 1;
	return (flags);
}
