#include "monty.h"
/**
* _div - divides the top value
* @stack: double pointer stack
* @line_number: line count
* Return: Void
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int results;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		;
		return;
	}

	results = ((*stack)->next->n) / ((*stack)->n);
	pop_opcode(stack, line_number);
	(*stack)->n = results;
}
