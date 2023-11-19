#include "monty.h"

/**
* addnode - add node to top of stack
* @head: first node
* @new: new value
*
* Return: none
*/

void addnode(stack_t **head, int new)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("this is Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;

	new_node->new = new;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

