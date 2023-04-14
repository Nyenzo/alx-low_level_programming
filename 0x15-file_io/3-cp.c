#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * print_error - Prints error message to stderr.
 * @msg: The error message to print.
 * @exit_code: The exit code to use when terminating the program.
 */
void print_error(const char *msg, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(exit_code);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command line arguments.
 * @argv: An array of pointers to the command line arguments.
 *
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	if (argc != 3)
		print_error("Usage: cp file_from file_to", 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file", 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
		print_error("Error: Can't write to file", 99);

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_error("Error: Can't write to file", 99);
	}

	if (bytes_read == -1)
		print_error("Error: Can't read from file", 98);

	if (close(fd_from) == -1)
		print_error("Error: Can't close fd", 100);

	if (close(fd_to) == -1)
		print_error("Error: Can't close fd", 100);

	return 0;
}
