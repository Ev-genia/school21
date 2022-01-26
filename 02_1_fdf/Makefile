# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 11:55:00 by mlarra            #+#    #+#              #
#    Updated: 2022/01/19 18:05:29 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRCS		=	fdf.c	map.c	error_exit.c	matrix.c	draw.c	init.c	\
				utils.c

SRCS_B		=	fdf_bonus.c		map_bonus.c		error_exit_bonus.c	\
				matrix_bonus.c	draw_bonus.c	init_bonus.c	utils_bonus.c\
				keypress_bonus.c

SRCS_GNL	=	${GNL_DIR}/get_next_line.c	${GNL_DIR}/get_next_line_utils.c

HEADER		=	fdf.h

HEADER_B	=	fdf_bonus.h

HEADER_GNL	=	${GNL_DIR}/get_next_line.h

OBJS		=	${SRCS:.c=.o}

OBJS_GNL	=	${SRCS_GNL:.c=.o}

OBJS_B		=	${SRCS_B:.c=.o}

CFLAGS		=	-Wall -Wextra -Werror

FRAMEWORKS	=	-framework OpenGL -framework AppKit

CC			=	gcc

RM			=	rm -f

LIB_MLX		=	/Users/mlarra/Documents/02_1_fdf/minilibx_macos

LIB_FT		=	./00_libft

GNL_DIR		=	./gnl

.PHONY:	all clean fclean re bonus

.o		:	%.c ${HEADER} %.c ${HEADER_GNL}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS} ${HEADER} ${OBJS_GNL} ${HEADER_GNL}
			make -C ${LIB_FT}
			${CC} ${CFLAGS} -I ${LIB_MLX} ${SRCS} ${SRCS_GNL} -L ${LIB_MLX} \
			-lmlx -L ${LIB_FT} -lft ${FRAMEWORKS} -o ${NAME}

all		:	${NAME}

clean	:
			${RM} ${OBJS} ${OBJS_GNL} ${OBJS_B}
			make -C ${LIB_FT} clean

fclean	:	clean
			${RM} ${NAME}
			cd ./00_libft && ${MAKE} fclean

re		:	fclean all

bonus	:	${OBJS_B} ${HEADER_B} ${OBJS_GNL} ${HEADER_GNL}
			make -C ${LIB_FT}
			${CC} ${CFLAGS} -I ${LIB_MLX} ${SRCS_B} ${SRCS_GNL} \
			-L ${LIB_MLX} -lmlx -L ${LIB_FT} -lft ${FRAMEWORKS} -o ${NAME}

norm	:	
			norminette ${SRCS} ${SRCS_B} ${SRCS_GNL} ${LIB_FT} ${HEADER} \
			${HEADER_B} ${HEADER_GNL}