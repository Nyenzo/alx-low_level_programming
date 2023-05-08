/* File: main.c
 * Author: Nyenzo
 * Description: Example usage of file operations functions
 */

#include "main.h"
#include <stdio.h>

int main() {
    const char *filename = "example.txt";
    size_t letters = 100;

    ssize_t result = read_textfile(filename, letters);
    if (result == -1) {
        printf("Failed to read file.\n");
    } else {
        printf("Read %zd letters from file.\n", result);
    }

    return 0;
}
