#include "monty.h"
#include <unistd.h>

int ARG = 1;
int is_int(char *str)
{
        int i = 0;

        if (str == NULL)
                return (0);
        if (*str == '-')
                i++;
        for (; str[i]; i++)
        {
                if (!isdigit(str[i]))
                        return (0);
        }
        return (1);
}

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
        stack_t *new, *tmp;
        char *push_arg = strtok(NULL, "\n \t");
        int pVal;
        /*if push, tests if the push_arg was valid or not */
        if (!is_int(push_arg))
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
        pVal = atoi(push_arg);
        new = malloc(sizeof(stack_t));

        if (new == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new->n = pVal;
        new->prev = NULL;
        new->next = NULL;
        /** checks if stack is empty **/
        if ((*stack) == NULL)
                *stack = new;
        else if (ARG)
        {
                /** puts new node on top if not empty **/
                (*stack)->prev = new;
                new->next = *stack;
                *stack = new;
        }
        else
        {
                /**puts new node on the bottom **/
                tmp = *stack;
                while (tmp->next != NULL)
                        tmp = tmp->next;
                tmp->next = new;
                new->prev = tmp;
        }
}
