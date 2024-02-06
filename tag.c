#include "push_swap.h"

int greater_than_tag(t_stack *stack, t_stack_elem *tag_head)
{
    int count_kept;
    int index;
    t_stack_elem *current;

    count_kept = 1;
    if (stack && tag_head)
    {
        index = tag_head->index;
        tag_head->keep = 1;
        current = tag_head->next;
        while (current != tag_head)
        {
            if (current->index > index)
            {
                count_kept++;
                index = current->index;
                current->keep = 1;
            }
            else
                current->keep = 0;
            current = current->next;
        }
    }
    return (count_kept);
}

void get_tag_head(t_stack *stack, int (*tag_function)(t_stack *, t_stack_elem *))
{
    int i;
    int current_kept;
    t_stack_elem *current;

    if (stack)
    {
        i = 0;
        current = stack->head;
        while (i < stack->size)
        {
            current_kept = tag_function(stack, current);
            if (current_kept > stack->kept)
            {
                stack->tag_head = current;
                stack->kept = current_kept;
            }
            else if (current_kept == stack->kept && (!stack->tag_head || current->value < stack->tag_head->value))
                stack->tag_head = current;
            i++;
            current = current->next;
        }
    }
    tag_function(stack, stack->tag_head);
}