#define DEFINE_VARIABLES
#include "monty.h"

/**
 * tokenize_line - splits a line into tokens
 * @line: the address of the line
 * Return: an array of tokens, else NULL
 */
char **tokenize_line(char *line)
{
	int i = 0;
	char *tok, **ins_arr = NULL;

	if (line == NULL)
		return (NULL);

	ins_arr = malloc(sizeof(char *) * 3);
	if (ins_arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((tok = __strtok_r(line, " \t\n", &line)))
	{
		ins_arr[i] = tok;
		i++;
	}

	return (ins_arr);
}

/**
 * repl_file - read each line and executes the command and print the output
 * @filename: the name of the file
 * Return: nothing
 */
void repl_file(char *filename)
{
	unsigned int line_num = 0;
	FILE *fileStream;
	char *line = NULL;

	fileStream = fopen(filename, "r");
	if (fileStream == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}

	if (!check_file_extension(filename))
	{
		fprintf(stderr, "Error: Invalid file extension\n");
        fclose(fileStream);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * BUFSIZE);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
        fclose(fileStream);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, BUFSIZE, fileStream) != NULL)
	{
		line_num++;
		tokens = tokenize_line(line);
		execute_ins(line_num);
	}

	fclose(fileStream);
}
