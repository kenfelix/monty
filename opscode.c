#include "monty.h"

/**
 * push - adds data to the top of the stack
 * breaks string into series of tokens using delimeter
 * @stack: indicating a doubly linkedlist
 * @line_number: the number line
 *
 * Description: check paraams params variable against input strings
 * then, locate stack beased on the order of input arguements
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
	register int num;
	char *params = strtok(NULL, "\n");

	if (check_string(params) == -1)
	{
		fprintf(stderr, "L%u: usage push integer \n", line_number);
		free(params);
		exit(EXIT_FAILURE);
	}
	num = atoi(params);
	add_dnodeint(stack, num);
}

/**
 * pall - prints everything in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}
