#include "monty.h"

/**
  * stack_count - count the elements in a stack
  * @stack: pointer to head of the stack
  *
  * Return: count
  */
size_t stack_count(stack_t **stack)
{
	stack_t *temp = *stack;
	size_t count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return (count);
}
