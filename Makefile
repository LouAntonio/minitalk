CC			= cc
FLAGS		= -Wall -Werror -Wextra

SERVER		= server
CLIENT		= client
SRCS_S		= server.c
SRCS_C		= client.c
SRCS_S_B	= server_bonus.c
SRCS_C_B	= client_bonus.c

OBJS_S		= $(SRCS_S:.c=.o)
OBJS_C		= $(SRCS_C:.c=.o)
OBJS_S_B	= $(SRCS_S_B:.c=.o)
OBJS_C_B	= $(SRCS_C_B:.c=.o)

FTPRINTF	= ft_printf/libftprintf.a

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_S) $(OBJS_C) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_S} ft_printf/libftprintf.a -o ${SERVER}
		${CC} ${FLAGS} ${OBJS_C} ft_printf/libftprintf.a -o ${CLIENT}

bonus:	$(OBJS_S_B) $(OBJS_C_B) $(FTPRINTF)
		${CC} ${FLAGS} ${OBJS_S_B} ft_printf/libftprintf.a -o ${SERVER}
		${CC} ${FLAGS} ${OBJS_C_B} ft_printf/libftprintf.a -o ${CLIENT}

$(FTPRINTF):
		${MAKE} -C ./ft_printf

clean:	
		$(MAKE) clean -C ./ft_printf
		rm -f ${OBJS_S} ${OBJS_C} ${OBJS_S_B} ${OBJS_C_B}

fclean:	clean
		$(MAKE) fclean -C ./ft_printf
		rm -f $(SERVER) $(CLIENT)

re:	fclean all