/* File: file_operations.c
 * Author: Nyenzo
 * Description: Implementation of file operations functions
 */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to read and print a text file */
ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0; /* Return 0 if filename is NULL */
    }

    int fd = open(filename, O_RDONLY); /* Open file in read-only mode */
    if (fd == -1) {
        perror("Error opening file");
        return 0; /* Return 0 on error */
    }

    char *buffer = (char *)malloc(sizeof(char) * (letters + 1)); /* Allocate memory for buffer */
    if (buffer == NULL) {
        perror("Error allocating memory");
        close(fd);
        return 0; /* Return 0 on error */
    }

    ssize_t bytes_read = read(fd, buffer, letters); /* Read from file into buffer */
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        free(buffer);
        return 0; /* Return 0 on error */
    }

    buffer[bytes_read] = '\0'; /* Null-terminate the buffer */
    printf("%s", buffer); /* Print buffer contents */

    close(fd);
    free(buffer);
    return bytes_read; /* Return number of bytes read */
}
