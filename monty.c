#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0 (success)
*/
int main(int argc, char **argv)
{
	FILE *opened_file = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t n_read;

	if (argc < 2 || argc > 2) /* check number of arguments */
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	opened_file = fopen(argv[1], "r"); /* open file to read */

	if (opened_file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else /* Read each line of opened file */
	{
		while ((n_read = getline(&line, &len, opened_file)) != -1)
		{
			printf("%s\n", line);
		}
		free(line);
	}
	fclose(opened_file);

	return (0);
}
