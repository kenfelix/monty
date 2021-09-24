#include "monty.h"

/**
 * add_dnodeint - adds a node at the beginning
 * @head: doubly linked list
 * @n: data of a node
 * Return: Doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * print_dlistint - prints doubly linked list
 * @h: doubly linked list
 * Return: Size of linked list
 */
size_t print_dlistint(const stack_t *h)
{
	size_t character = 0;

	while (h)
	{
		character++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (character);
}
