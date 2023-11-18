#include "monty.h"

void f_push(stack_t **stack_head, unsigned int line_number)
{
    int value, index = 0, invalid_flag = 0;

    if (new_bus.arg)
    {
        if (new_bus.arg[0] == '-')
            index++;
        while (new_bus.arg[index] != '\0')
        {
            if (new_bus.arg[index] > 57 || new_bus.arg[index] < 48)
                invalid_flag = 1;
            index++;
        }
        if (invalid_flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(new_bus.file);
            free(new_bus.content);
            free_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(new_bus.file);
        free(new_bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    value = atoi(new_bus.arg);

    if (new_bus.lifo == 0)
        add_node(stack_head, value);
    else
        add_queue(stack_head, value);
}
