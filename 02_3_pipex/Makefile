# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 15:05:06 by mlarra            #+#    #+#              #
#    Updated: 2022/03/09 15:58:14 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS_DIR	=	src

SRCS_BONUS_DIR	= src_bonus

SRCS	=	pipex.c	ft_split.c	ft_execve.c	ft_strjoin.c	ft_strncmp.c\
			utils.c

SRCS_BONUS	= pipex_bonus.c	ft_split_bonus.c	ft_execve_bonus.c\
			ft_strjoin_bonus.c	ft_strncmp_bonus.c	utils_bonus.c\
			ft_pipex_here_doc.c	get_next_line.c	get_next_line_utils.c

SOURCES	=	${addprefix ${SRCS_DIR}/, ${SRCS}}

SOURCES_BONUS	= ${addprefix ${SRCS_BONUS_DIR}/, ${SRCS_BONUS}}

OBJ_DIR	=	objects

OBJ		=	${SOURCES:${SRCS_DIR}/%.c=${OBJ_DIR}/%.o}

OBJ_BONUS	=	${SOURCES_BONUS:${SRCS_BONUS_DIR}/%.c=${OBJ_DIR}/%.o}

HEADER	=	${SRCS_DIR}/pipex.h

HEADER_BONUS	=	${SRCS_BONUS_DIR}/pipex_bonus.h

CFLAGS	=	-Wall -Wextra -Werror -g

CC		=	gcc

RM		=	rm -f

.PHONY	:	all	clean	fclean	re	bonus norm

${OBJ_DIR}/%.o	:	${SRCS_DIR}/%.c ${HEADER}
	@mkdir ${OBJ_DIR} 2> /dev/null || true
	${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o	:	${SRCS_BONUS_DIR}/%.c ${HEADER_BONUS}
	@mkdir ${OBJ_DIR} 2> /dev/null || true
	${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJ}
	${CC} ${CFLAGS} $^ -o ${NAME}

all		:	${NAME}

clean	:
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}
	@rmdir ${OBJ_DIR} 2> /dev/null || true

fclean	:	clean
	${RM} ${NAME}

re		:	fclean	all

bonus	:
	@make OBJ="${OBJ_BONUS}" all

norm	:
	norminette ${SRCS} ${SRCS_BONUS}
	norminette ${HEADER} ${HEADER_BONUS}
