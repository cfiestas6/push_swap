#include "./push_swap.h"

static void set_rotation_data(t_move_data new_move_data, t_move_data *move_data, int size)
{
    if (move_data->done && size >= move_data->size)
        return ;
    move_data->elem_a = new_move_data.elem_a;
    move_data->elem_b = new_move_data.elem_b;
    move_data->rotation_a = new_move_data.rotation_a;
    move_data->rotation_b = new_move_data.rotation_b;
    move_data->size = size;
}

static void get_rotation_costs(t_stack *stack, int index, int *cost_rx, int *cost_rrx)
{
    t_stack_elem *current;

    if (!stack | !stack->head)
        return ;
    current = stack->head;
    while (current->index != index)
    {
        (*cost_rx)++;
        current = current->next;
    }
    current = stack->head;
    while (current->index != index)
    {
        (*cost_rrx)++;
        current = current->previous;
    }
}

static t_stack_elem *get_a_elem_after(t_stack *stack_a, int index)
{
    t_stack_elem *current;

    current = stack_a->tag_head;
    if (index < current->index)
        while (index < current->previous->index && current->index > current->previous->index)
            current = current->previous;
    else
    {
        while (index > current->index && current->index < current->next->index)
            current = current->next;
        if (index > current->index && current->index > current->next->index)
            current = current->next;
    }
    return (current);
}

static void optimize_rotation(t_stack *stack_a, t_stack *stack_b, t_move_data *move_data, t_stack_elem *elem_b)
{
    t_move_data new_move_data;
    int cost_ra;
    int cost_rra;
    int cost_rb;
    int cost_rrb;

    cost_ra = 0;
    cost_rra = 0;
    cost_rb = 0;
    cost_rrb = 0;
    new_move_data.elem_a = get_a_elem_after(stack_a, elem_b->index);
    new_move_data.elem_b = elem_b;
    get_rotation_costs(stack_a, new_move_data.elem_a->index, &cost_ra, &cost_rra);
    get_rotation_costs(stack_b, new_move_data.elem_b->index, &cost_rb, &cost_rrb);
    new_move_data.rotation_a = R;
    new_move_data.rotation_b = R;
    set_rotation_data(new_move_data, move_data, MAX(cost_ra, cost_rb));
    new_move_data.rotation_a = RR;
    set_rotation_data(new_move_data, move_data, cost_ra + cost_rb);
    new_move_data.rotation_b = RR;
   	set_rotation_data(new_move_data, move_data, MAX(cost_rra, cost_rrb)); 
    new_move_data.rotation_a = R;
    set_rotation_data(new_move_data, move_data, cost_rra + cost_rb);
}

void get_best_rotation(t_stack *stack_a, t_stack *stack_b, t_move_data *move_data)
{
    t_stack_elem    *current;
    int             i;

    if (!stack_b)
        return ;
    i = 0;
    current = stack_b->head;
    while (i < stack_b->size)
    {
        optimize_rotation(stack_a, stack_b, move_data, current);
        current = current->next;
        i++;
    }
}