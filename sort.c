#include "push_swap.h"

static void fix_a(t_stack *stack_a, t_command_list *command_list)
{
    t_stack_elem *current;
    int cost_ra;
    int cost_rra;

    if (!stack_a || !stack_a->head)
        return ;
    cost_ra = 0;
    current = stack_a->head;
    while (current->index > 0)
    {
        cost_ra++;
        current = current->next;
    }
    cost_rra = 0;
    current = stack_a->head;
    while (current->index > 0)
    {
        cost_rra++;
        current = current->previous;
    }
    while (stack_a->head->index > 0 && (cost_ra < cost_rra))
        ra(stack_a, command_list);
    while (stack_a->head->index > 0 && !(cost_ra < cost_rra))
        rra(stack_a, command_list);
}

t_command_list *sort(t_stack *stack_a, int (*tag_function)(t_stack *, t_stack_elem *))
{
    t_stack *stack_b;
    t_command_list *command_list;

    command_list = init_command_list();
    stack_b = create_stack();
    sort_a(stack_a, stack_b, command_list, tag_function);
    sort_b(stack_a, stack_b, command_list);
    fix_a(stack_a, command_list);
    free_stack(stack_b);
    return (command_list);
}


// while stack_a has elems keep = 0
    // 