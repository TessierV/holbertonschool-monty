#include "monty.h"

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
