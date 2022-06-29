# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 14:48:13 by mlarra            #+#    #+#              #
#    Updated: 2022/06/29 00:20:02 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC		=	main.c	ft_atoi.c	ft_check.c	ft_free.c	ft_init.c\
			ft_print.c	ft_sleep.c	ft_utils.c	ft_check_malloc.c	ft_forks.c

HEADER	=	philo.h

OBJ		=	${SRC:%.c=%.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

RM		=	rm -f

.PHONY	:	all	clean	fclean	re	bonus	norm

%.o	:	%.c	${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ}
	${CC} ${CFLAGS} $^ -o $@

all		:	${NAME}

clean	:
	${RM} ${OBJ}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

norm	:
	norminette ${SOURCES} ${HEADER}