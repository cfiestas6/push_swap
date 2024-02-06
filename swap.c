#include "push_swap.h"

void sa(t_stack *stack_a, t_command_list *command_list)
{
    if (stack_a->size >= 2)
    {
        t_stack_elem *first;
        t_stack_elem *second;
        int temp_value;

        first = stack_a->head;
        second = first->next;
        temp_value = first->value;
        first->value = second->value;
        second->value = temp_value;
    }
    if (command_list)
        add_command(command_list, create_command("sa"));
}

void sb(t_stack *stack_b, t_command_list *command_list)
{
    if (stack_b->size >= 2)
    {
        t_stack_elem *first;
        t_stack_elem *second;
        int temp_value;

        first = stack_b->head;
        second = first->next;
        temp_value = first->value;
        first->value = second->value;
        second->value = temp_value;
    }
    if (command_list)
        add_command(command_list, create_command("sb"));
}

void ss(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    sa(stack_a, NULL);
    sb(stack_b, NULL);
    if (command_list)
        add_command(command_list, create_command("ss"));
}