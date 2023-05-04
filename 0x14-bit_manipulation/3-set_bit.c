#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to unsigned long integer
 * @index: index of the bit to set to 1, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* Check if index is out of bounds */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Create a mask with only the bit at the index set to 1 */
	mask = 1UL << index;

	/* Perform bitwise OR to set the bit at index to 1 */
	*n |= mask;

	return (1);
}
