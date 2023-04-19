#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr elf_header;
    unsigned char *e_ident;

    if (argc != 2)
    {
        printf("Usage: %s <ELF file>\n", argv[0]);
        return (1);
    }

    /* Open the ELF file */
    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return (1);
    }

    /* Read the ELF header */
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
    {
        perror("read");
        close_elf(fd);
        return (1);
    }

    e_ident = elf_header.e_ident;

    /* Check if the file is an ELF file */
    check_elf(e_ident);

    /* Print the ELF header information */
    printf("ELF Header:\n");
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_abi(e_ident);
    print_osabi(e_ident);
    print_type(elf_header.e_type, e_ident);
    print_entry(elf_header.e_entry, e_ident);

    /* Close the ELF file */
    close_elf(fd);

    return (0);
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            fprintf(stderr, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
    int index;

    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");

}
