# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 13:19:37 by mlarra            #+#    #+#              #
#    Updated: 2022/02/10 02:31:10 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SOURCE	=	push_swap.c	ft_split.c		my_atoi.c	op_swap.c	op_push.c\
			op_rotate.c	op_reverse.c	lst_utils.c	exit_func.c	check_func.c\
			sort_func.c	score_func.c	utils.c

OBJ		=	${SOURCE:.c=.o}

HEADER	=	push_swap.h

CFLAGS	=	-Wall -Wextra -Werror -g

CC		=	gcc

RM		=	rm -f

.PHONY	:	all clean fclean re bonus norm

.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJ} ${HEADER}
			${CC} ${CFLAGS} ${SOURCE} -o ${NAME}

all		:	${NAME}

clean	:
			${RM} ${OBJ}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

# bonus	:	${OBJ_B} ${HEADER_B}
# 			${CC} ${CFLAGS} ${SOURCE_B} -o ${NAME}

norm	:
			norminette ${SOURCE} ${HEADER}