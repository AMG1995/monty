#include "monty.h"

/**
 * f_print_string - prints the ASCII characters from the stack
 * @stack_top: pointer to the top node of the stack
 * @line_number: line number in the script (unused in this function)
 *
 * Return: none
 */
void f_print_string(stack_t **stack_top, unsigned int line_number)
{
	stack_t *current_node;

	(void)line_number;

	for (current_node = *stack_top; current_node; current_node = current_node->next)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
	}
	printf("\n");
}

