#include "push_swap.h"

void get_indexes(t_stack *stack)
{
    t_stack_elem *current;
    t_stack_elem *other;
    int count;
    int first;

    if (!stack->head)
        return ;
    current = stack->head;
    first = 1;
    while (first || current != stack->head)
    {
        count = 0;
        other = stack->head;
        first = 1;
        while (first || other != stack->head)
        {
            if (other->value < current->value)
                count++;
            other = other->next;
            first = 0;
        }
        current->index = count;
        current = current->next;
        first = 0;
    }
}
