#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @head: double pointer to the head of the stack
 * @line_number: line number in the file
 * @value: value to push onto the stack
 */
void push(stack_t **head, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * pall - prints all values on the stack
 * @head: pointer to the head of the stack
 */
void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

