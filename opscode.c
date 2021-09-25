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
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%s %s", tokens[0], tokens[1]);
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
	if (tokens[1])
	{
		fprintf(stderr, "L%d: usage: pall", line_number);
		exit(EXIT_FAILURE);
	}

	print_dlistint(*stack);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: the stack data structure
 * @line_number: the line number of the instruction
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (tokens[1])
	{
		fprintf(stderr, "L%d: usage: pint", line_number);
		exit(EXIT_FAILURE);
	}

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	print_top(*stack);
}