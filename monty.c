#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argc
 * Return: success on exit, exit failure otherwise
 */

int main(int argc, char **argv)
{
	int i = 0;
	char *op = argv[1];
	stack = NULL;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	while (ins[i].opcode && op)
	{
		if (strcmp(op, ins[i].opcode) == 0)
				{
					ins[i].f(&(stack), argc);
				}
		else
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}
