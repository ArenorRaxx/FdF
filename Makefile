# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:58:34 by mcorso            #+#    #+#              #
#    Updated: 2022/01/24 13:29:53 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# src/obj
SRC_FILES = main.c \
	key_manager.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# mlx
MLX = ./external/mlx_linux/
MLX_LIB = $(addprefix $(MLX), libmlx_Linux.a)
MLX_INC = -I $(MLX)
MLX_LNK = -L $(MLX) -l mlx -L/usr/lib -lXext -lX11

# dir
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
HEAD = ./

all: obj $(MLX_LIB) ${NAME}

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(HEAD) -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) -lm -o ${NAME}

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all