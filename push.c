#include "push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    if (stack_b->size > 0)
    {
        t_stack_elem *temp;
        
        temp = stack_b->head;
        stack_b->head = stack_b->head->next;
        stack_b->size--;
        temp->next = stack_a->head;
        stack_a->head = temp;
        stack_a->size++;
    }
    if (command_list)
        add_command(command_list, create_command("pa"));
}

void pb(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    if (stack_a->size > 0)
    {
        t_stack_elem *temp;
        
        temp = stack_a->head;
        stack_a->head = stack_a->head->next;
        stack_a->size--;
        temp->next = stack_b->head;
        stack_b->head = temp;
        stack_b->size++;
    }
    if (command_list)
        add_command(command_list, create_command("pb"));
}