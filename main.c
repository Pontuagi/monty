#include "monty.h"

carry free_memory;

/**
* main - entry point
* @ac: argument count
* @av: argument value(number of lines)
*
* Return: 0 if success else 1
*/
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t line_size;
	char *filename = av[1];

	free_memory.fp = fopen(filename, "r");
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!free_memory.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	line_size = getline(&free_memory.line, &len, free_memory.fp);
	while (line_size >= 0)
	{
		line_number++;
		op_selector(&stack, line_number);
		line_size = getline(&free_memory.line, &len, free_memory.fp);
	}

	free(free_memory.line);
	free_stack(&stack);
	fclose(free_memory.fp);
	return (EXIT_SUCCESS);
}
