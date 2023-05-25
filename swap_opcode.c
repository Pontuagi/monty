#include "monty.h"

/**
  * swap_opcode - swap the first two elements of the stack
  * @stack: head of the stack
  * @line_number: line number of the bytecode
  */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	int first;
	int second;
	size_t count;

	count = stack_count(stack);
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;
	(*stack)->n = second;
	(*stack)->next->n = first;
}
