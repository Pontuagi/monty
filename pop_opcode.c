 #include "monty.h"

/**
  * pop_opcode - pop the first element of the stack
  * @stack: pointer to head of the stack
  * @line_number: number of the line
  */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
