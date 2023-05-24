#include "monty.h"
carry free_memory;
/**
* main - entry point
* @argc: argument count
* @argv: argument value(number of lines)
* Return: 0 if success else 1
*
*/
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t line_size;
	char *filename = argv[1];

	free_memory.fp = fopen(filename, "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!free_memory.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_size = getline(&free_memory.line, &len, free_memory.fp);
	while (line_size >= 0)
	{
		line_number++;
		opcode_selector(&stack, line_number);
		line_size = getline(&free_memory.line, &len, free_memory.fp);
	}

	free(free_memory.line);
	kai(&stack);
	fclose(free_memory.fp);
	return (EXIT_SUCCESS);
}
