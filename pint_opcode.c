#include "monty.h"
#include <stdio.h>
/**
* pint - pint prints the value at the top of the stack
* @stack: The double pointer to a struct stack
* @line_number: The number of line
*
* Return: Nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	/*checks if the stack is empty, else prints value*/
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;

	printf("%d\n", (*stack)->n);
}
