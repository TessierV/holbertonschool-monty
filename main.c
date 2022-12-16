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