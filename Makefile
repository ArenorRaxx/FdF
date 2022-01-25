# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:58:34 by mcorso            #+#    #+#              #
#    Updated: 2022/01/25 12:26:15 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# src/obj
SRC_FILES = main.c \
	chain.c \
	graphics.c \
	parsing.c \
	window_manager.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# mlx
MLX = ./external/mlx_linux/
MLX_LIB = $(addprefix $(MLX), libmlx_Linux.a)
MLX_INC = -I $(MLX)
MLX_LNK = -L $(MLX) -l mlx -L/usr/lib -lXext -lX11

# gnl
GNL = ./external/gnl/
GNL_LIB = $(addprefix $(GNL), get_next_line.a)
GNL_LNK = -L $(GNL) -l get_next_line

# dir
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
HEAD = ./

all: obj $(GNL_LIB) $(MLX_LIB) ${NAME}

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/gnl/%.c:$(GNL)%.C

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(HEAD) -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX)

$(GNL_LIB):
	make -C $(GNL)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(GNL_LIB) $(MLX_LNK) -lm -o ${NAME}

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX) clean
	make -C $(GNL) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(GNL) fclean

re: fclean all