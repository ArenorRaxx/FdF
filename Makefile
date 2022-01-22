# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:58:34 by mcorso            #+#    #+#              #
#    Updated: 2022/01/22 05:20:04 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC_FILES = main.c
OBJ_FILES = ${SRC_FILES:.c=.o}

SRCS = ${addprefix $(SRC_DIR), ${SRC_FILES}}
OBJS = ${addprefix $(OBJ_DIR), ${OBJ_FILES}}

HEAD = ./
NAME = fdf

CC = gcc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -f

all:	${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} ./mlx_linux/libmlx_Linux.a -I ./mlx_linux/ -lXext -lX11 -o ${NAME}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -I${HEAD} -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:
	fclean all

.PHONY: all ${NAME} clean fclean re
