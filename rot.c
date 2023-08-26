#include "monty.h"
/**
 * rot1 - The opcode rotl rotates the stack to the top.
 * @stack: pointer
 * count: counter
 * Return: void
 */
void rot1(stack_t **stack, unsigned int count)
{

	stack_t *c, *head;
	(void) count;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	c = *stack;
	head = c->next;
	head->prev = NULL;

	while (c->next != NULL)
		c = c->next;
	c->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = c;
	*stack = head;
}
/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @count: counter
 * @stack: pointer
 * Return: void
 */
void rotr(stack_t **stack, unsigned int count)
{

	stack_t *c;
	(void) count;

	if (!stack || !(*stack) || !(*stack)->next)
		return;
	c = *stack;
	while (c->next != NULL)
		c = c->next;
	c->next = *stack;
	c->prev->next = NULL;
	c->prev = NULL;
	(*stack)->prev = c;
	(*stack) = c;
}
