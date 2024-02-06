#include "push_swap.h"

static int needs_pb(t_stack *stack_a)
{
    int i;
    t_stack_elem *current;

    if (!stack_a)
        return (0);
    i = 0;
    current = stack_a->head;
    while (i < stack_a->size)
    {
        if (!current->keep)
            return (1);
        i++;
        current = current->next;
    }
    return (0);
}

static int needs_sa(t_stack *stack_a, int (*tag_function) (t_stack *, t_stack_elem *))
{
    int count_kept;

    if (!stack_a || stack_a->size < 2)
        return (0);
    sa(stack_a, NULL);
    count_kept = tag_function(stack_a, stack_a->tag_head);
    sa(stack_a, NULL);
    tag_function(stack_a, stack_a->tag_head);
    if (count_kept > stack_a->kept)
        return (1);
    return (0);
}

void sort_a(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list, int (*tag_function) (t_stack *, t_stack_elem *))
{
    while (needs_pb(stack_a))
    {
        if (needs_sa(stack_a, tag_function))
        {
            sa(stack_a, command_list);
            stack_a->kept = tag_function(stack_a, stack_a->tag_head);
        }
        else if (stack_a->head->keep == 0)
            pb(stack_a, stack_b, command_list);
        else
            ra(stack_a, command_list);
    }
}