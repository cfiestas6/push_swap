#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_gt;
	t_stack *stack_idx;
	t_command_list *command_gt;

	if (argc < 2)
		return (0);
	init_stacks(&stack_gt, &stack_idx, argc, argv);
	get_indexes(stack_gt);
	get_tag_head(stack_gt, &greater_than_tag);
	command_gt = sort(stack_gt, &greater_than_tag);

	free_stack(stack_gt);
	free_stack(stack_idx);

	print_commands(command_gt);

	free_command_list(command_gt);
	return (0);
}