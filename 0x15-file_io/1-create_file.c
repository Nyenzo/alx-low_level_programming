/* File: file_operations.c
 * Author: Nyenzo
 * Description: Implementation of file operations functions
 */

#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to append text to a file */
int append_text_to_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1; /* Return -1 if filename is NULL */
    }

    if (text_content == NULL) {
        return 1; /* Return 1 if text_content is NULL */
    }

    int fd = open(filename, O_WRONLY | O_APPEND); /* Open file in write-only mode with append flag */
    if (fd == -1) {
        perror("Error opening file");
        return -1; /* Return -1 on error */
    }

    size_t text_len = strlen(text_content); /* Calculate length of text_content */
    ssize_t bytes_written = write(fd, text_content, text_len); /* Write text_content to file */
    if (bytes_written == -1 || (size_t)bytes_written != text_len) {
        perror("Error writing to file");
        close(fd);
        return -1; /* Return -1 on error */
    }

    close(fd);
    return 1; /* Return 1 on success */
}
