#include "monty.h"

/**
 * main - The executing function
 * @argc: the number of arguments passed, including the program's name
 * @argv: an array of the passed arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    repl_file(argv[1]);
    exit(EXIT_FAILURE);
}

/**
 * check_file_extension - checks if the extension of a filename is .c
 * @filename: name of the file given by user
 * Return: 1 if true, else 0
 */
int check_file_extension(char *filename)
{
    int n;

    if (filename == NULL)
    {
        fprintf(stderr, "No file name given.\n");
        exit(EXIT_FAILURE);
    }

    n = strlen(filename) - 2;

    return ((strcmp(filename + n, ".m") == 0) ? 1 : 0);
}

/**
 * execute_ins - Executes an instruction based on the instruction set.
 * @line_num: the line number of the current function
 * Return: 0 on success, else EXIT_FAILURE
 */
int execute_ins(unsigned int line_num)
{
    int i = 0;
    instruction_t ins_sets[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL},
    };

    while (ins_sets[i].opcode)
    {
        if (strcmp(tokens[0], ins_sets[i].opcode) == 0)
        {
            ins_sets[i].f(&stack, line_num);
            return (0);
        }
        i++;
    }

    if (ins_sets[i].opcode == NULL)
    {
        fprintf(stderr, "L<%d>: unknown instruction <%s>",
                line_num, tokens[0]);
        free(tokens);
    }

    exit(EXIT_FAILURE);
}
