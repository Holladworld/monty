#include "monty.h"
#include <ctype.h>
/**
 * sub - The opcode sub subtracts the top element of the stack from
 * the second top element of the stack.
 * @index: double pointer to first node
 * @count: line count
 * Return: nothing
 */
void sub(stack_t **index, unsigned int count)
{
	stack_t *current;
	int flip;

	if (!index || !(*index) || !((*index)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	current = *index;

	flip = current->next->n - current->n;
	pop(index, count);
	pop(index, count);
	add_node(index, flip);
}

