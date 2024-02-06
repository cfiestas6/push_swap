#include "push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        write_error_and_exit();
    stack->head = NULL;
    stack->size = 0;
    stack->kept = 0;
    stack->tag_head = NULL;
    return stack;
}

t_stack_elem *create_stack_elem(int value)
{
    t_stack_elem *elem = (t_stack_elem *)malloc(sizeof(t_stack_elem));
    if (!elem)
        write_error_and_exit();
    elem->value = value;
    elem->index = 0;
    elem->keep = 0;
    elem->next = NULL;
    elem->previous = NULL;
    return elem;
}

void add_to_stack(t_stack *stack, t_stack_elem *elem)
{
   if (!stack->head) 
    {
        elem->next = elem;
        elem->previous = elem;
        stack->head = elem;
    }
    else
    {
        elem->next = stack->head;
        elem->previous = stack->head->previous;
        stack->head->previous->next = elem;
        stack->head->previous = elem;
    }
    stack->size++;
}

void free_stack(t_stack *stack)
{
    t_stack_elem *current;
    t_stack_elem *next;

    current = stack->head;
    if (current)
    {
        next = current->next;
        while (next != stack->head)
        {
            free(current);
            current = next;
            next = current->next;
        }
        free(current);
    }
    free(stack);
}

void print_stack_elem(t_stack_elem *elem)
{
    ft_printf("Value: %d\n", elem->value);
    ft_printf("Index: %d\n", elem->index);
    ft_printf("Keep?: %d\n\n", elem->keep);
}

void print_stack(t_stack *stack)
{
	int i;
	t_stack_elem *current;

    if (!stack->head)
        return ;
	current = stack->head;
	i = 0;
	while (current->next != stack->head)
	{
		ft_printf("%d\n", i);
        print_stack_elem(current);
		current = current->next;
		i++;
	}
    print_stack_elem(stack->head);
}
