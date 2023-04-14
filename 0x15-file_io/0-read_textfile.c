/* File: file_operations.c
 * Author: [Your Name]
 * Description: Implementation of file operations functions
 */

#include "file_operations.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function to read and print a text file */
ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        printf("Error: filename is NULL\n");
        return 0;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 0;
    }

    char buf[letters];
    ssize_t bytesRead = read(fd, buf, letters);
    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return 0;
    }

    ssize_t bytesWritten = write(STDOUT_FILENO, buf, bytesRead);
    if (bytesWritten == -1) {
        perror("Error writing to STDOUT");
        close(fd);
        return 0;
    }

    close(fd);
    printf("\n");
    return bytesWritten;
}
