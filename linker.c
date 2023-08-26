#include "monty.h"
/**
 * print_prev - link list in reverse
 * @stack: pointer
 * Return: nodes
 */
size_t print_prev(stack_t *stack)
{
	size_t rev = 0;

	while (stack->next)
	{
		stack = stack->next;
	}
	while (stack)
	{
		stack = stack->prev;
		rev++;
	}
	return (rev);
}

/**
 * delete: delete node at index
 * @stack: pointer
 * @index: unsigned int
 * Return: -1 
 */
int delete(stack_t **stack, unsigned int index)
{
	stack_t *c;
	unsigned int ptr = 0;

	if (!stack)
		return (-1);
	c = *stack;
	if (index == 0)
	{
		if (c->next)
		{
			c->next->prev = NULL;
			*stack = c->next;
		}
		else
			*stack = NULL;
		free(c);
		return (1);
	}
	while (c)
	{
		if (ptr == index)
		{
			if (c->next)
			{
				c->prev->next = c->next;
				c->next->prev = c->prev;
			}
			else
				c->prev->next = NULL;
			free(c);
			return (1);
		}
		c = c->next;
		ptr++;
	}
	return (-1);
}
