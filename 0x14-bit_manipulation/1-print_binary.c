#include "main.h"
#include <stdio.h>

/**
 * print_binary - Print the binary representation of a number
 * @n: Unsigned long integer to print in binary
 *
 * Return: None
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flag = 0;

	while (mask)
	{
		if (n & mask)
		{
			putchar('1');
			flag = 1;
		}
		else if (flag)
			putchar('0');

		mask >>= 1;
	}

	if (!flag)
		putchar('0');
}
