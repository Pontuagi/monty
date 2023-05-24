#include "monty.h"

/**
  * opcode_push - push an element into a stack
  * @stack: top of stack
  * @line_number: line number in stack
  *
  * Return: nothing
  */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *tok;
	stack_t *new_node = NULL;
	int no = 0;

	tok = strtok(free_memory.line, DELIMITERS);
	if (tok == NULL)
	{
		free_file();
		free_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tok[no] != '\0')
	{
		if ((no == 0 && tok[no] == '-') || (tok[no] >= '0' && tok[no] <= '9'))
		{
			no++;
		}
		else
		{
		free_file();
		free_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}
		no++;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(tok);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
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
	stack_t *printer = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;
	while (printer != NULL)
	{
		printf("%d\n", printer->n);
		printer = printer->next;
	}
}
