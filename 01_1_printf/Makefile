# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 11:55:00 by mlarra            #+#    #+#              #
#    Updated: 2021/11/08 16:33:22 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_printf.c	ft_print_str.c	ft_print_char.c	ft_print_dig.c\
			ft_print_nbr.c	ft_itoa_p.c	ft_print_p.c	ft_print_x.c\
			ft_init.c	ft_print_percent.c	ft_print_i_min_value.c\
			ft_print_nbr_0.c	ft_print_nbr_pozitive_negative.c

HEADER	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

CC	= gcc

RM	= rm -f

.PHONY:	all clean fclean re bonus

.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS} ${HEADER}
			cd ./libft && ${MAKE}
			ar rcs ${NAME} libft/*.o $?

all		:	${NAME}

clean	:
			${RM} ${OBJS}
			cd ./libft && ${MAKE} clean

fclean	:	clean
			${RM} ${NAME}
			cd ./libft && ${MAKE} fclean
	
re		:	fclean all
