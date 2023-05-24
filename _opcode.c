#include "monty.h"
/**
* op_selector - for selecting options
* @stack: for stack
* @line_number: number of lines
* Return: Nothing
*/
void op_selector(stack_t **stack, unsigned int line_number)
{
	int target = 0, idx = 0;
	char *token = strdup(free_memory.line);

	instruction_t op[] = {{"push", opcode_push}, {"pint", pint}, {"pall", opcode_pall},
	{NULL, NULL}};

	free_memory.temp = token;
	token = strtok(token, DELIMITERS);
	if (token == NULL)
	{
		free(free_memory.temp);
		return;
	}
	else if (token[0] != '\0' && token[0] == '#')
	{
		free(free_memory.temp);
		return;
	}
	/*iterate*/
	while (op[idx].opcode != NULL)
	{
		if (strcmp(token, op[idx].opcode) == 0)
		{
			target = 1;
			(op[idx].f)(stack, line_number);
			break;
		}
		idx++;
	}
	if (target == 0)
	{
		fprintf(stderr, "L%u: unknown institution %s\n", line_number, token);
		free_file();
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	free(free_memory.temp);
}
