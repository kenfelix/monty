#ifndef MONTY_H
#define MONTY_H

/* Header Files */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

/* Macros */
#define BUFSIZE 80

/* Data Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variable */
#ifdef DEFINE_VARIABLES
#define EXTERN
#else
#define EXTERN extern
#endif
EXTERN char **tokens;
EXTERN stack_t *stack;

/* My Functions Prototypes */
char *read_line(FILE *stream, long pos);
int check_file_extension(char *filename);
char **tokenize_line(char *);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(const stack_t *h);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
int execute_ins(unsigned int line_num);
void repl_file(char *filename);
int is_alpha(char *str);

#endif
