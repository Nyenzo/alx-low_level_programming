#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return -1;

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = sys_open(filename, O_WRONLY | O_APPEND);
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
