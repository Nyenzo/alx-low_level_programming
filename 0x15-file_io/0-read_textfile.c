/* File: file_operations.c
 * Author: [Nyenzo]
 * Description: Implementation of file operations functions
 */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to read and print a text file */
ssize_t read_textfile(const char *filename, size_t letters) {
    int fd = open(filename, O_RDONLY); /* Open file in read-only mode */
    if (fd == -1) {
        perror("Error opening file");
        return 0; /* Return 0 on error */
    }

    char *buffer = (char *)malloc(letters); /* Allocate memory for buffer */
    if (buffer == NULL) {
        perror("Error allocating memory");
        close(fd);
        return 0; /* Return 0 on error */
    }

    ssize_t bytes_read = read(fd, buffer, letters); /* Read from file */
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        free(buffer);
        return 0; /* Return 0 on error */
    }

    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read); /* Write to standard output */
    if (bytes_written == -1 || bytes_written != bytes_read) {
        perror("Error writing to standard output");
        close(fd);
        free(buffer);
        return 0; /* Return 0 on error */
    }

    close(fd);
    free(buffer);
    return bytes_written; /* Return the actual number of bytes written */
}
