# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 13:19:37 by mlarra            #+#    #+#              #
#    Updated: 2022/02/15 12:17:30 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

SOURCE		=	push_swap.c	ft_split.c		my_atoi.c	op_swap.c	op_push.c\
				op_rotate.c	op_reverse.c	lst_utils.c	exit_func.c\
				check_func.c	sort_func.c	score_func.c	utils.c

SOURCE_B	=	push_swap_bonus.c	check_func_bonus.c	ft_split_bonus.c\
				lst_utils_bonus.c	exit_func_bonus.c	my_atoi_bonus.c\
				op_push_swap_bonus.c	op_rotates_bonus.c	utils_bonus.c

OBJ			=	${SOURCE:.c=.o}

OBJ_B		=	${SOURCE_B:.c=.o}

HEADER		=	push_swap.h

HEADER_B	=	push_swap_bonus.h

CFLAGS		=	-Wall -Wextra -Werror -g

CC			=	gcc

RM			=	rm -f

.PHONY		:	all clean fclean re bonus norm

.o			:	%.c ${HEADER} ${HEADER_B}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJ} ${HEADER}
				${CC} ${CFLAGS} ${SOURCE} -o ${NAME}

${NAME_B}	:	${OBJ_B} ${HEADER_B}
				${CC} ${CFLAGS} ${SOURCE_B} -o ${NAME_B}

all			:	${NAME}

clean		:
				${RM} ${OBJ}
				${RM} ${OBJ_B}

fclean		:	clean
				${RM} ${NAME}
				${RM} ${NAME_B}

re			:	fclean all

bonus		:	${NAME_B}

norm		:
				norminette -R CheckForbiddenSourceHeader ${SOURCE}
				norminette -R CheckDefine ${HEADER}
				norminette -R CheckForbiddenSourceHeader ${SOURCE_B}
				norminette -R CheckDefine ${HEADER_B}