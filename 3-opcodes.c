#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 *
 * @stack: the stack
 * @line_number: the line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swp = 0;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swp;
}
