# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 13:19:37 by mlarra            #+#    #+#              #
#    Updated: 2022/01/25 13:11:25 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SOURCE	=	push_swap.c	ft_split.c	ft_atoi.c	ft_strchr.c	operations.c

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