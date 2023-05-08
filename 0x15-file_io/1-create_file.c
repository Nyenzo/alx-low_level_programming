#include "createfile.h"

/**
 * create_file - Creates a file with the given filename and writes
 *               the specified text content to it.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return -1;

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = sys_open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return -1;

	if (text_content != NULL)
	{
		w = sys_write(fd, text_content, len);
		if (w == -1)
		{
			sys_close(fd);
			return -1;
		}
	}

	sys_close(fd);
	return 1;
}
