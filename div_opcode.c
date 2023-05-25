#include "monty.h"
/**
* _div - divides the top value
* @stack: double pointer stack
* @line_number: line count
* Return: Void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *result;

	result = *stack;
	if ((*stack) == NULL || result == NULL || (*stack)->next == NULL)
	{
		free_file();
		free_stack(stack);

		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = result->n;
	if (i == 0)
	{
		free_file();
		free_stack(stack);

		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	(*stack)->n = (*stack)->n / i;
	free(result);
}
