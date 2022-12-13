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
		printf("exit");
	}
	file_in = fopen(argv[1], "r");
	while (getline(&line, &linesize_t, file_in) != -1)
	{
		line_number++;
		func = get_function(line);
		func->f(&stack, line_number);
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
		if (strcmp(func->opcode, "push") == 0)
			func->f = push;
		if (strcmp(func->opcode, "pall") == 0)
			func->f = pall;
	}
	return (func);
}
