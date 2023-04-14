/* File: main.c
 * Author: [Nyenzo]
 * Description: Example usage of file operations functions
 */

#include "main.h"
#include <stdio.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    size_t letters = 100;

    ssize_t result = read_textfile(filename, letters);
    if (result == 0) {
        printf("Failed to read and print text file.\n");
    } else {
        printf("Successfully read and printed %zd bytes from text file.\n", result);
    }

    return 0;
}
