#include "monty.h"

/**
* pint - pint prints the value at the top of the stack
* @stack: The double pointer to a struct stack
* @line_number - The number of line
*
* Return: Nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	/*checks if the stack is empty, else prints value*/
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
