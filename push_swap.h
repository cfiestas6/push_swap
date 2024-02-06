#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "./ft_printf/ft_printf.h"

# define MAX(a, b) (a > b ? a : b)

typedef enum
{
	R,
	RR
}	t_rotation;

typedef struct s_stack_elem
{
	int value;
	int index;
	int keep;
	struct s_stack_elem	*next;
	struct s_stack_elem	*previous;
} t_stack_elem;

typedef struct s_stack
{
	t_stack_elem *head;
	int size;
	int kept;
	t_stack_elem *tag_head;
} t_stack;

typedef struct s_command
{
	char *name;
	struct s_command *next;
} t_command;

typedef struct s_command_list
{
	t_command *head;
	int size;
} t_command_list;

typedef struct s_move_data
{
	t_stack_elem *elem_a;
	t_stack_elem *elem_b;
	int rotation_a;
	int rotation_b;
	int size;
	int done;
} t_move_data;

void write_error_and_exit();
void ft_strcpy(const char *src, char *dest, int length);
int ft_strlen(const char *str);
char **ft_split(const char *str);
int count_words(const char *str);
int ft_atoi(const char *str);
int count_numbers(int argc, char **argv);

void check_for_duplicates(int *numbers, int count);
void check_for_not_numbers(int argc, char **argv);
void get_indexes(t_stack *stack);
//void index_tag(t_stack *stack, t_stack_elem *tag_head);

int greater_than_tag(t_stack *stack, t_stack_elem *tag_head);
void get_tag_head(t_stack *stack, int (*tag_function)(t_stack *, t_stack_elem *));

int *parse_args(int argc, char **argv, int count);
void write_error_and_exit(void);
int is_number(const char *str);

t_stack *create_stack(void);
t_stack_elem *create_stack_elem(int value);
void add_to_stack(t_stack *stack, t_stack_elem *elem);
void free_stack(t_stack *stack);
void init_stacks(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void print_stack(t_stack *stack);

void sort_a(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list, int (*tag_function) (t_stack *, t_stack_elem *));
void sort_b(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);
t_command_list *sort(t_stack *stack_a, int (*tag_function)(t_stack *, t_stack_elem *));
t_command_list *init_command_list(void);
t_command *create_command(char *name);
void add_command(t_command_list *command_list, t_command *new_command);
void print_commands(t_command_list *command_list);
void free_command_list(t_command_list *command_list);
void get_best_rotation(t_stack *stack_a, t_stack *stack_b, t_move_data *move_data);

void sa(t_stack *stack_a, t_command_list *command_list);
void sb(t_stack *stack_b, t_command_list *command_list);
void ss(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);
void pa(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);
void pb(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);
void ra(t_stack *stack_a, t_command_list *command_list);
void rb(t_stack *stack_b, t_command_list *command_list);
void rr(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);
void rra(t_stack *stack_a, t_command_list *command_list);
void rrb(t_stack *stack_b, t_command_list *command_list);
void rrr(t_stack *stack_a, t_stack *stack_b, t_command_list *command_list);

#endif