#include "monty.h"
#include <ctype.h>
/**
 * divid -  divides the second top element of the stack by the top
 * element of the stack.
 * @ck: double pointer to head
 * @count: counter
 * Return: void
 */
void divid(stack_t **ck, unsigned int count)
{
	stack_t *currt;
	int flip;

	if (!ck || !(*ck) || !(*ck)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	currt = *ck;

	if (currt->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	flip = currt->next->n / currt->n;
	pop(ck, count);
	pop(ck, count);
	add_node(ck, flip);
}

/**
 * mod -  computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * element of the stack.
 * @stack: double pointer
 * @count: count unsigned int
 * Return: void
 */
void mod(stack_t **stack, unsigned int count)
{
	stack_t *currt;
	int flip;

	if (!(*stack) || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	currt = *stack;
	if (currt->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	flip = currt->next->n % currt->n;
	pop(stack, count);
	pop(stack, count);
	add_node(stack, flip);
}
