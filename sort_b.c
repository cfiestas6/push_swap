#include "push_swap.h"

static t_move_data  *init_move_data(void)
{
    t_move_data *move_data;
    
    if (!(move_data = malloc(sizeof(t_move_data))))
        return (NULL);
    move_data->size = 0;
    move_data->done = 0;
    move_data->elem_a = NULL;
    move_data->elem_b = NULL;
    move_data->rotation_a = R;
    move_data->rotation_b = R;
    return (move_data);
}

void move_b(t_stack *stack_a, t_stack *stack_b, t_move_data *move_data, t_command_list *command_list)
{
    while (move_data->elem_a != stack_a->head || move_data->elem_b != stack_b->head)
    {
        if (move_data->rotation_a == move_data->rotation_b && move_data->elem_a != stack_a->head
            && move_data->elem_b != stack_b->head)
        {
            if (move_data->rotation_a == R)
                rr(stack_a, stack_b, command_list);
            else
                rrr(stack_a, stack_b, command_list);
        }
        else if (move_data->elem_a != stack_a->head)
        {
            if (move_data->rotation_a == R)
                ra(stack_a, command_list);
            else
                rra(stack_a, command_list);
        }
        else if (move_data->elem_b != stack_b->head)
        {
            if (move_data->rotation_b == R)
                rb(stack_b, command_list);
            else
                rrb(stack_b, command_list);
        }
    }
}


void sort_b(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list)
{
    t_move_data *move_data;

    move_data = init_move_data();
    while (stack_b->size)
    {
        move_data->done = 0;
        get_best_rotation(stack_a, stack_b, move_data);
        move_b(stack_a, stack_b, move_data, command_list);
        pa(stack_a, stack_b, command_list);
    }
    free(move_data);
}