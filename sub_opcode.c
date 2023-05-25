#include "main.h"

/**
  * sub_opcode - subtract the first element from the second element in stack
  * and store in the second element. the first element is removed
  * @stack: pointer to head of the stack
  * @line_number: line number of byte code
  */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i = 0;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_file();
		free_stack(stack);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	i = temp->n;
	(*stack)->n = (*stack)->n - i;
	free(temp);
}
