CC					= cc
FLAGS				= -Wall -Werror -Wextra

NAME				= minitalk

NAME1				= server
NAME2				= client
NAME1_SRC			= server.c
NAME2_SRC			= client.c
OBJS_NAME1			= $(NAME1_SRC:.c=.o)
OBJS_NAME2			= $(NAME2_SRC:.c=.o)

NAME1_BONUS			= server_bonus
NAME2_BONUS			= client_bonus
NAME1_SRC_BONUS		= server_bonus.c
NAME2_SRC_BONUS		= client_bonus.c
OBJS_NAME1_BONUS	= $(NAME1_SRC_BONUS:.c=.o)
OBJS_NAME2_BONUS	= $(NAME2_SRC_BONUS:.c=.o)

FTPRINTF	= ft_printf/libftprintf.a

all: $(NAME1) $(NAME2)

$(NAME): $(NAME1) $(NAME2)

$(NAME1): $(OBJS_NAME1) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_NAME1} $(FTPRINTF) -o ${NAME1}

$(NAME2): $(OBJS_NAME2) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_NAME2} $(FTPRINTF) -o ${NAME2}

bonus: $(NAME1_BONUS) $(NAME2_BONUS)

$(NAME1_BONUS): $(OBJS_NAME1_BONUS) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_NAME1_BONUS} $(FTPRINTF) -o ${NAME1_BONUS}

$(NAME2_BONUS): $(OBJS_NAME2_BONUS) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_NAME2_BONUS} $(FTPRINTF) -o ${NAME2_BONUS}

$(FTPRINTF):
		${MAKE} -C ./ft_printf

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:	
		$(MAKE) clean -C ./ft_printf
		rm -f ${OBJS_NAME1} ${OBJS_NAME2} ${OBJS_NAME1_BONUS} ${OBJS_NAME2_BONUS}

fclean:	clean
		$(MAKE) fclean -C ./ft_printf
		rm -f $(NAME1) $(NAME2) $(NAME1_BONUS) $(NAME2_BONUS)

re:	fclean all