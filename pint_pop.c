#include "monty.h"
/**
 * pint - The opcode pint prints the value at the top
 * of the stack, followed by a new line.
 * @stack_node: pointer to stack
 * @count: line count
 * Return: void
 */
void pint(stack_t **stack_node, unsigned int count)
{
	if (!*stack_node || !stack_node)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_node)->n);
}

/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack_node: pointer to stack head
 * @count: line count
 * Return: void
 */
void pop(stack_t **stack_node, unsigned int count)
{
	stack_t *current;

	if (!*stack_node || !stack_node)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	current = *stack_node;
	if (current->next)
	{
		current->next->prev = NULL;
		*stack_node = current->next;
	}
	else
		*stack_node = NULL;
	free(current);
}
