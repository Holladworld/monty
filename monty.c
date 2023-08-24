#include "monty.h"

/**
 * main - entry point of monty interpreter
 * @argc: argument count
 * @argv: argument vector (program file)
 * Return: 0 as success
 */
stack_t **global_var;

int main(int argc, char *argv[])
{
	FILE *program;
	size_t buff = 0;
	stack_t *head = NULL;
	unsigned int count = 0;
	char *str;
	char *siz = NULL;

	global_var = &head;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	program = fopen(argv[1], "r");

	if (!program)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack();
		exit(EXIT_FAILURE);
	}
	while ((getline(&str, &buff, program)) != (-1))
	{
		count++;
		siz = strtok(str, DIVIDERS);
		if (siz != NULL && siz[0] != '#')
			monty_opcode(siz, &head, count);
	}
	fclose(program);
	if (str)
		free(str);
	free_stack();
	return (0);
}

/**
 * free_stack - free stack memory
 * Return: void
 */
void free_stack(void)
{
	stack_t *head;
	stack_t *current = NULL;

	head = *global_var;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
