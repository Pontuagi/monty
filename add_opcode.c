#include "monty.h"
/**
* add - performs add operation of two
* elements at the stack
* @stack: double pointer to stack
* @line_number: number of line
*
* Return: Void
*/
void add(stack_t **stack, unsigned int line_number)
{
	/*declare three variables*/
	int x = 0;
	int y = 0;
	int temp = 0;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;

	temp = x + y;
	pop(stack, line_number);
	(*stack)->n = temp;
}
