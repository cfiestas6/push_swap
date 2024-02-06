#include "push_swap.h"

void ra(t_stack *stack_a, t_command_list *command_list)
{
    if (stack_a->size > 1)
    {
        t_stack_elem *temp;
        t_stack_elem *last;

        temp = stack_a->head;
        stack_a->head = stack_a->head->next;
        temp->next = NULL;
        last = stack_a->head;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
    if (command_list)
        add_command(command_list, create_command("ra"));
}

void rb(t_stack *stack_b, t_command_list *command_list)
{
    if (stack_b->size > 1)
    {
        t_stack_elem *temp;
        t_stack_elem *last;

        temp = stack_b->head;
        stack_b->head = stack_b->head->next;
        temp->next = NULL;
        last = stack_b->head;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
    if (command_list)
        add_command(command_list, create_command("rb"));
}

void rr(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    ra(stack_a, NULL);
    rb(stack_b, NULL);
    if (command_list)
        add_command(command_list, create_command("rr"));
}

void rra(t_stack *stack_a, t_command_list  *command_list)
{
    if (stack_a->size > 1)
    {
        t_stack_elem *last;
        t_stack_elem *prev;

        last = stack_a->head;
        prev = NULL;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stack_a->head;
        stack_a->head = last;
    }
    if (command_list)
        add_command(command_list, create_command("rra"));
}

void rrb(t_stack *stack_b, t_command_list *command_list)
{
    if (stack_b->size > 1)
    {
        t_stack_elem *last;
        t_stack_elem *prev;
        
        last = stack_b->head;
        prev = NULL;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stack_b->head;
        stack_b->head = last;
    }
    if (command_list)
        add_command(command_list, create_command("rrb"));
}

void rrr(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    rra(stack_a, NULL);
    rrb(stack_b, NULL);
    if (command_list)
        add_command(command_list, create_command("rrr"));
}