#include "monty.h"

/**
 * monty_opcode - function to search for functions and operation code
 * @op: operator to be searched
 * @head: the start of our pointer.
 * @count: the line count of current number
 * Return: Nothing
 */
void monty_opcode(char *op, stack_t **head, unsigned int count)
{
	size_t operator;

	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (operator = 0; instruction[operator].opcode; operator++)
	{
		if (strcmp(instruction[operator].opcode, op) == 0)
		{
			instruction[operator].f(head, count);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", count, op);
	free_stack();
	exit(EXIT_FAILURE);
}
