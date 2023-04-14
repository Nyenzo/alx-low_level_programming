#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Function to read and print a text file */
ssize_t read_textfile(const char *filename, size_t letters);
/* Function to append text to a file */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
