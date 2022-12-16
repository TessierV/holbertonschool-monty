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

	if ((*stack) == NULL || (stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_t(*stack);

		exit(EXIT_FAILURE);
	}
	swp = (*stack)->n;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_t(*stack);

		exit(EXIT_FAILURE);
	}
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = swp;
}
