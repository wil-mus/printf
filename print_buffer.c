#include "main.h"

/**
 * prints_buffer - print buffer and reset index
 *
 * @buffer: buffer to be printed
 * @buff_ind: pointer of index buffer
 */

void prints_buffer(char buffer[], int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
