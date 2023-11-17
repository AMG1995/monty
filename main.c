#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	bus_t bus_info = {NULL, NULL, NULL, 0};
	char *line_content;
	FILE *monty_file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	bus_info.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; read_line > 0; line_number++)
	{
		line_content = NULL;
		read_line = getline(&line_content, &size, monty_file);
		bus_info.content = line_content;

		if (read_line > 0)
		{
			execute(line_content, &stack, line_number, monty_file);
		}

		free(line_content);
	}

	free_stack(stack);
	fclose(monty_file);

	return (0);
}

