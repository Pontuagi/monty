#include "monty.h"

/**
  *
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;
	
	num = atoi(x);
	if (num != 0)
	{
		new_node = (new_node*)malloc(sizeof(stack_t));
		if (new_node == NULL)

		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = top;



	}
	else
	{
		printf("L%d: usage: push integer\n", x);
		exit(EXIT_FAILURE);
	}
}
