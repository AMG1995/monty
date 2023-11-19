#include "monty.h"

/**
 * f_pstr - print string at the top of stack
 * @head: first node of linked list
 * @counter: line counter
 *
 * Return: none
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	(void)counter;

	for (current_node = *head; current_node; current_node = current_node->next)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
	}
	printf("\n");
}

