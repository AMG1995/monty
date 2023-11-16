#include "monty.h"

/**
 * push_operation - Add node to the stack
 * @stack_head: Pointer to the head of the stack
 * @line_number: Line number in the file
 *
 * Description:
 * This function adds a node to the stack based on the provided value.
 */
void push_operation(stack_t **stack_head, unsigned int line_number)
{
    int value, index = 0, flag = 0;

    if (bus.argument)
    {
        if (bus.argument[0] == '-')
            index++;

        while (bus.argument[index] != '\0')
        {
            if (bus.argument[index] > 57 || bus.argument[index] < 48)
                flag = 1;
            index++;
        }

        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    value = atoi(bus.argument);

    if (bus.lifo == 0)
        add_node(stack_head, value);
    else
        add_queue(stack_head, value);
}

