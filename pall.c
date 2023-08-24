#include "monty.h"
/**
 * pall - function to print all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to stack list
 * @count: postion of monty stack file
 * Return: void
 */
void pall(stack_t **stack, unsigned int count __attribute__((unused)))
{
	stack_t *current = *stack;

	if (*stack && stack)
	{
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
