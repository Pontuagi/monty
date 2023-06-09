#include "monty.h"

/**
  * free_file - free memory space
  */
void free_file(void)
{
	free(free_memory.temp);
	free(free_memory.line);
	fclose(free_memory.fp);
}

/**
  * free_stack - free memory space
  * @stack: head of a stack
  */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while ((*stack) != NULL)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
	free((*stack));
}
