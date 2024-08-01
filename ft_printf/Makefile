# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 09:08:46 by lantonio          #+#    #+#              #
#    Updated: 2024/05/28 07:44:34 by lantonio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a



SRC			= 	ft_itoa.c 		\
				ft_printf.c 	\
				ft_putchar.c 	\
				ft_puthex.c 	\
				ft_putnbr.c 	\
				ft_putptr.c 	\
				ft_putstr.c 	\
				ft_putunsigned.c

OBJS 		= ${SRC:.c=.o}
LIBC 		= ar rcs
CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

${NAME}: ${OBJS}
			${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}
re: fclean all

.PHONY : all clean fclean re