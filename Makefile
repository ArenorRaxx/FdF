# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:58:34 by mcorso            #+#    #+#              #
#    Updated: 2022/03/07 11:40:25 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
UNAME = $(shell uname)

# src/obj
SRC_FILES = main.c \
	chain.c \
	graphics.c \
	hook_manager.c \
	image_manager.c \
	map_manager.c \
	parsing.c \
	window_manager.c

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# mlx
ifeq ($(UNAME), Linux)
	MLX = ./external/mlx_linux/
	MLX_LIB = $(addprefix $(MLX), libmlx_Linux.a)
	MLX_INC = -I $(MLX)
	MLX_LNK = -L $(MLX) -lmlx -L/usr/lib -lXext -lX11
endif
ifeq ($(UNAME), Darwin)
	MLX = ./external/mlx_osx/
	MLX_LIB = $(addprefix $(MLX), libmlx.a)
	MLX_INC = -I $(MLX)
	MLX_LNK = -L $(MLX) -lmlx -L/usr/lib -framework OpenGL -framework AppKit
endif

# gnl
GNL = ./external/gnl/
GNL_LIB = $(addprefix $(GNL), get_next_line.a)

# libft
LFT = ./external/libft/
LFT_LIB = $(addprefix $(LFT), libft.a)

# dir
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
HEAD = ./

all: obj $(GNL_LIB) $(LFT_LIB) $(MLX_LIB) ${NAME}

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(HEAD) -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX)

$(GNL_LIB):
	make -C $(GNL)

$(LFT_LIB):
	make -C $(LFT)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(GNL_LIB) $(LFT_LIB) $(MLX_LNK) -lm -o ${NAME}

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX) clean
	make -C $(GNL) clean
	make -C $(LFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(GNL) fclean
	make -C $(LFT) fclean

re: fclean all