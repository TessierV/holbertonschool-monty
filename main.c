#include "monty.h"
int ARG = 1;

/**
 * main - main function
 * @argc: int
 * @argv: char
 * Return: 0
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *file_in;
	size_t linesize_t = 0;
	stack_t *stack = NULL;
	instruction_t *func = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &linesize_t, file_in) != -1)
	{
		line_number++;
		func = get_function(line);
		if ((func->opcode) == NULL)
		{
			free(func);
			if (line)
				free(line);
			line = NULL;
			continue;
		}
		if (func->f)
			func->f(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, func->opcode);
			if (line)
				free(line);
			if (stack)
				free_t(stack);
			free(func);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}
		if (line)
			free(line);
		line = NULL;
		free(func);
	}
	if (line)
		free(line);
	free_t(stack);
	fclose(file_in);
	return (0);
}

/**
 * get_function - search the function
 * @line: char
 * Return: func
 */
instruction_t *get_function(char *line)
{
	char *opcode;
	instruction_t *func;
	opcode = strtok(line, " \n\t\r");
	func = malloc(sizeof(*func));
	if (func == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	func->opcode = opcode;
	func->f = NULL;
	if (func->opcode)
	{
		if (strcmp(func->opcode, "push") == 0)
			func->f = _push;
		if (strcmp(func->opcode, "pall") == 0)
			func->f = _pall;
		if (strcmp(func->opcode, "pint") == 0)
			func->f = _pint;
		if (strcmp(func->opcode, "pop") == 0)
			func->f = _pop;
		if (strcmp(func->opcode, "swap") == 0)
			func->f = _swap;
		if (strcmp(func->opcode, "add") == 0)
			func->f = _add;
		if (strcmp(func->opcode, "nop") == 0)
			func->f = _nop;
	}
	return (func);
}
