# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 11:55:00 by mlarra            #+#    #+#              #
#   Updated: 2021/11/17 16:46:52 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line

SRCS	=	get_next_line.c	get_next_line_utils.c

SRCS_B	=	get_next_line_bonus.c	get_next_line_utils_bonus.c

HEADER	=	get_next_line.h

HEADER_B =	get_next_line_bonus.h

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.PHONY:	all clean fclean re bonus

.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

all		:	${NAME}

clean	:
			${RM} ${OBJS} ${OBJS_B}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

bonus	:	${OBJS_B} ${HEADER_B}
			ar rcs ${NAME} $?
