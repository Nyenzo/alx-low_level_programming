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
#include <unistd.h>

/* Function to create a file */
int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1; /* Return -1 if filename is NULL */
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); /* Open file with desired permissions */
    if (fd == -1) {
        perror("Error creating file");
        return -1; /* Return -1 on error */
    }

    if (text_content != NULL) {
        ssize_t bytes_written = write(fd, text_content, strlen(text_content)); /* Write text_content to file */
        if (bytes_written == -1) {
            perror("Error writing to file");
            close(fd);
            return -1; /* Return -1 on error */
        }
    }

    close(fd);
    return 1; /* Return 1 on success */
}
