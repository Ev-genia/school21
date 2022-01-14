# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 11:55:00 by mlarra            #+#    #+#              #
#    Updated: 2022/01/13 15:20:48 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# all	:
# 	gcc -I /Users/eugenia/C/school21/02_1_fdf/minilibx_macos \
# 	main.c map.c ft_split.c ft_atoi.c get_next_line.c get_next_line_utils.c -L \
# 	/Users/eugenia/C/school21/02_1_fdf/minilibx_macos \
# 	-lmlx -framework OpenGL -framework AppKit -g

NAME		=	fdf

SRCS		=	fdf.c	#map.c draw.c

SRCS_B		=	fdf_bonus.c

SRCS_GNL	=	${GNL_DIR}/get_next_line.c	${GNL_DIR}/get_next_line_utils.c

HEADER		=	fdf.h

HEADER_B	=	fdf_bonus.h

HEADER_GNL	=	${GNL_DIR}/get_next_line.h

OBJS		=	${SRCS:.c=.o}

OBJS_GNL	=	${SRCS_GNL:.c=.o}

CFLAGS		=	-Wall -Wextra -Werror -g

FRAMEWORKS	=	-framework OpenGL -framework AppKit

CC			=	gcc

RM			=	rm -f
# home
LIB_MLX		=	/Users/eugenia/C/school21/02_1_fdf/minilibx_macos
# home
# LIB_FT		=	/Users/eugenia/C/school21/02_1_fdf/00_libft
# school
LIB_FT		=	./00_libft

GNL_DIR		=	./gnl

.PHONY:	all clean fclean re bonus

.o		:	%.c ${HEADER} %.c ${HEADER_GNL}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS} ${HEADER} ${OBJS_GNL} ${HEADER_GNL}
			make -C ${LIB_FT}
##			gcc -I /Users/eugenia/C/school21/02_1_fdf/minilibx_macos main.c -L /Users/eugenia/C/school21/02_1_fdf/minilibx_macos -lmlx -framework OpenGL -framework AppKit
			${CC} ${CFLAGS} -I ${LIB_MLX} ${SRCS} ${SRCS_GNL} -L ${LIB_MLX} -lmlx -L \
			${LIB_FT} -lft ${FRAMEWORKS} -o ${NAME}

all		:	${NAME}

clean	:
			${RM} ${OBJS} ${OBJS_GNL}
			make -C ${LIB_FT} clean

fclean	:	clean
			${RM} ${NAME}
			cd ./00_libft && ${MAKE} fclean

re		:	fclean all

bonus	:	${OBJS_B} ${HEADER_B} ${OBJS_GNL} ${HEADER_GNL}
			make -C ${LIB_FT}
			${CC} ${CFLAGS} -I ${LIB_MLX} ${SRCS_B} ${SRCS_GNL} -L ${LIB_MLX} \
			-lmlx -L ${LIB_FT} -lft ${FRAMEWORKS} -o ${NAME}
