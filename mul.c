#include "monty.h"
/**
 * mul - multiplies second top element of the stack with the top element
 * of the stack.
 * @stack: pointer to head
 * @count: current line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int count)
{
	stack_t *curt;
	int flip;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	curt = *stack;
	flip = curt->n * curt->next->n;
	pop(stack, count);
	pop(stack, count);
	add_node(stack, flip);
}

