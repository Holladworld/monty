#include "monty.h"
/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack: pointer to stack
 * @count: count line
 * Return: void
 */
void add(stack_t **stack, unsigned int count)
{
	int output;
	stack_t *current;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	current = *stack;

	output = current->n + current->next->n;
	pop(stack, count);
	pop(stack, count);
	add_node(stack, output);
}

/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: poniter to the stack
 * @index: start of the file
 * Return: error message L<line_number>: can't swap,
 * stack too short, followed by a new line
 */
void swap(stack_t **stack, unsigned int index)
{
	stack_t *current;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", index);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	(*stack)->prev = current;
	(*stack)->next = current->next;
	current->prev = NULL;
	if (current->next)
		current->next->prev = *stack;
	current->next = *stack;
	*stack = current;
}
