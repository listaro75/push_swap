NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRCS = main.c push_swap.c
LIBFT = ./libft/libft.a

all: $(NAME) libft 

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	cc ${FLAGS} ${SRCS} -o ${OBJS} ${NAME} 

.c.o:
	@cc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

clean:
	@rm -rf *.o
	@make -C ./libft clean

re: fclean all