#include "monty.h"
/**
 * is_digit - fucntion to check if a string is present
 * @agv: argument
 * @count: current position
 * Return: digit
 */
int is_digit(char *agv, unsigned int count)
{
	int digit;

	digit = atoi(agv);
	if (digit == 0 && strcmp(agv, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	return (digit);
}

/**
 * add_node - function to add node to list
 * @stack: pointer to the head of monty stack
 * @agv: our integer
 * Return: node
 */
stack_t *add_node(stack_t **stack, const int agv)
{
	stack_t *new_size, *current;

	new_size = malloc(sizeof(stack_t));
	if (!new_size)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_size);
		return (NULL);
	}
	new_size->n = agv;
	new_size->prev = NULL;
	current = *stack;

	if (!*stack)
	{
		new_size->next = NULL;
	}
	else
	{
		new_size->next = current;
		current->prev = new_size;
	}
	*stack = new_size;
	return (new_size);
}

