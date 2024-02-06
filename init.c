#include "push_swap.h"

void init_stacks(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
    int count;
    int *numbers;
    int i;
    t_stack_elem *new_elem;
    
    *stack_a = create_stack();
    *stack_b = create_stack();
    count = count_numbers(argc, argv);
    numbers = parse_args(argc, argv, count);
    check_for_duplicates(numbers, count);
    check_for_not_numbers(argc, argv);
    i = 0;
    while (i < count)
    {
        new_elem = create_stack_elem(numbers[i]);
        if (!new_elem)
            return;
        add_to_stack(*stack_a, new_elem);
        i++;
    }
    free(numbers);
}

t_command_list *init_command_list(void)
{
    t_command_list *command_list;

    command_list = malloc(sizeof(t_command_list));
    if (!command_list)
        write_error_and_exit();
    command_list->head = NULL;
    command_list->size = 0;
    return (command_list);
}