#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: the stack
 * @line_number: the line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}
