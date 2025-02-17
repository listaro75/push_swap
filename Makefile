NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRCS = main.c ruler1.c verif.c manag.c ruler2.c ruler3.c init_stack.c algo.c algo_1.c algo_2.c algo_3.c \
algo_4.c
LIBFT = ./libft/libft.a 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	cc ${FLAGS} ${SRCS} ${LIBFT} -o ${OBJS}  ${NAME} -g

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