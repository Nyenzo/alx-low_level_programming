#include "main.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return -1; // Return -1 if filename is NULL

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // Open file with desired permissions
	if (fd == -1)
	{
		perror("Error creating file");
		return -1; // Return -1 on error
	}

	if (text_content != NULL)
	{
		ssize_t bytes_written = write(fd, text_content, strlen(text_content)); // Write text_content to file
		if (bytes_written == -1)
		{
			perror("Error writing to file");
			close(fd);
			return -1; // Return -1 on error
		}
	}

	close(fd);
	return 1; // Return 1 on success
}
