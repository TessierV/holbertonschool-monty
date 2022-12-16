#include "monty.h"
/**
 * _pint - print the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pall - print all values
 *
 * @stack: head stack
 * @line_number: current line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;/* = *stack;*/
	(void) line_number;
	tmp = *stack;
	/*while (stack && tmp)*/
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
