// binary_conversion.c

#include <stdio.h>
#include "main.h"

unsigned int binary_to_uint(const char *b) {
    if (b == NULL) {
        printf("Error: Input string is NULL.\n");
        return 0;
    }

    unsigned int result = 0;
    int i = 0;

    // Loop through each character in the string until null terminator is reached
    while (b[i] != '\0') {
        // Check if the character is not '0' or '1'
        if (b[i] != '0' && b[i] != '1') {
            printf("Error: Invalid character '%c' at position %d.\n", b[i], i);
            return 0;
        }

        // Shift the current result to the left by 1 bit
        result <<= 1;
        // Add the current character to the result after converting it from char to int
        result += (b[i] - '0');
        i++;
    }

    return result;
}
