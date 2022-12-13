#include "monty.h"

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
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[2], "r");
	if (!file_in)
	{
		fprintf(stdout,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &linesize_t, file_in) != -1)
	{
		line_number++;
		func = get_function(line);
		func->f(&stack, line_number);
		if (!func)
		{
			fprintf(stdout, "L%d: unknown instruction %s\n", line_number, func->opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file_in);
	return (0);
}

instruction_t *get_function(char *line)
{
	char *opcode;
	instruction_t *func;

	opcode = strtok(line, " \n\t\r");
	func = malloc(sizeof(*func));
	func->opcode = opcode;

	if (func->opcode)
	{
		/*if (strcmp(func->opcode, "push") == 0)
			func->f = _push;*/
		if (strcmp(func->opcode, "pall") == 0)
			func->f = _pall;
		if (strcmp(func->opcode, "pint") == 0)
			func->f = _pint;
		if (strcmp(func->opcode, "pop") == 0)
			func->f = _pop;
		/*if (strcmp(func->opcode, "swap") == 0)
			func->f = _swap;
		if (strcmp(func->opcode, "add") == 0)
			func->f = _add;
		if (strcmp(func->opcode, "nop") == 0)
			func->f = _nop;*/
	}
	return (func);
}
