#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * print_error - Prints error message to stderr.
 * @msg: The error message to print.
 * @exit_code: The exit code to use when terminating the program.
 */
void print_error(const char *msg, int exit_code)
{
	fprintf(stderr, "%s\n", msg);
	exit(exit_code);
}

/**
 * display_elf_header - Displays the information in the ELF header.
 * @header: A pointer to the ELF header.
 */
void display_elf_header(Elf64_Ehdr *header)
{
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class: %d-bit\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);

	printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "little-endian" : "big-endian");

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);

	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf("Type: 0x%04x\n", header->e_type);

	printf("Entry point address: 0x%lx\n", header->e_entry);

	printf("Format: %d\n", header->e_version);
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
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename", 97);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't open file", 98);

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Can't read file", 98);

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file", 98);

	display_elf_header(&header);

	if (close(fd) == -1)
		print_error("Error: Can't close file", 99);

	return 0;
}
