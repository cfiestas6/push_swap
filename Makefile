CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = main.c init.c index.c sort.c tag.c parse.c stack.c rotation.c utils.c split.c command.c sort_a.c rotate.c swap.c push.c sort_b.c
OBJ = $(SRC:.c=.o)
PRINTF = ft_printf

all: $(PRINTF) $(NAME)

$(PRINTF):
	make -C $(PRINTF)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(PRINTF)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF)

re: fclean all