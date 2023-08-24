#include "monty.h"
/**
 * push -function to push element to monty stack
 * @head: pointer to the first node
 * @count: line (current) counter
 * Return: nothing
 */
void push(stack_t **head, unsigned int count)
{
	int ags;
	char *digit;

	digit = strtok(NULL, DIVIDERS);

	if (!digit)
	{
		fprintf(stderr, "L%u: usuage: push interger\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	ags = is_digit(digit, count);
	if (!add_node(head, ags))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
}
