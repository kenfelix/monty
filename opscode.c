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
	int num;

	if (tokens[1] == NULL || is_alpha(tokens[1]))
	{
		fprintf(stderr, "L<%d>: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(tokens[1]);
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
