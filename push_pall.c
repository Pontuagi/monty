#include "monty.h"

/**
  * opcode_push - push an element into a stack
  * @stack: top of stack
  * @line_number: line number in stack
  * @value: element to push to stack
  *
  * Return: nothing
  */
void opcode_push(stack_t **stack, unsigned int line_number, char *value)
{
	int no;
	stack_t *new_node;

	if (value == NULL || *value == '\0')
	{
		fprintf(stderr, "L%d: usage : push interger\n", line_number);
		exit(EXIT_FAILURE);
	}
	no = atoi(value);
	if (no == 0 && *value != '0')
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = no;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
  * opcode_pall - print all the values of the stack starting from the top
  * @stack: top of stack
  * @line_number: line number of stack
  *
  * Return: nothing
  */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
