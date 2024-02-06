#include "push_swap.h"

t_command *create_command(char *name)
{
    t_command *command;

    command = malloc(sizeof(t_command));
    command->name = name;
    command->next = NULL;
    return (command);
}

void add_command(t_command_list *command_list, t_command *new_command)
{
    t_command *head;

    if (!command_list || !new_command)
        return ;
    if (!command_list->head)
        command_list->head = new_command;
    else
    {
        head = command_list->head;
        while (head->next)
            head = head->next;
        head->next = new_command;
    }
    command_list->size++;
}

void print_commands(t_command_list *command_list)
{
    t_command *current;

    if (!command_list)
        return ;
    current = command_list->head;
    while (current)
    {
        ft_printf("%s\n", current->name);
        current = current->next;
    }
}

void free_command_list(t_command_list *command_list)
{
    t_command *current;
    t_command *next;

    if (!command_list)
        return ;
    current = command_list->head;
    while (current)
    {
        current = next;
        next = next->next;
        free(current->name);
        free(current);
    }
    free(command_list);
}