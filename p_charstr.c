#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: double pointer to head
 * @count: counter
 * Return: void
 */
void pstr(stack_t **head, unsigned int count __attribute((unused)))
{
	stack_t *c = *head;

	while (c && (c->n != 0) && ((c->n) > 32) && (( c->n) < 128))
	{
		printf("%c", c->n);
		c = c->next;
	}
	putchar('\n');
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @head: double pointer to head node
 * @count: countet
 * Return: void
 */
void pchar(stack_t **head, unsigned int count)
{
	int stack;

	if (!head || !(*head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	stack = 0;
	stack = (*head)->n;
	if ((stack < 33) || (stack > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
	}
	putchar(stack);
	putchar('\n');
}
