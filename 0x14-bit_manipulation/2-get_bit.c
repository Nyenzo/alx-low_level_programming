#include "main.h"

/**
 * get_bit - retrieves the value of a bit at a given index
 * @n: unsigned long integer
 * @index: index of the bit to retrieve, starting from 0
 *
 * Return: value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	/* Check if index is out of bounds */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Create a mask with only the bit at the index set to 1 */
	mask = 1UL << index;

	/* Perform bitwise AND to retrieve the value of the bit at index */
	if (n & mask)
		return (1);
	else
		return (0);
}
