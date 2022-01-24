# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 19:57:57 by mcorso            #+#    #+#              #
#    Updated: 2022/01/24 20:15:58 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#files
SRC_FILES = get_next_line.c \
	get_next_line_utils.c

OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

#meta
CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=50
NAME = get_next_line.a

#dir
HEAD = ./
SRC_DIR = ./
OBJ_DIR = ./objs/

all		: obj $(NAME)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $(addprefix $(OBJ_DIR), ${<:.c=.o})

obj		:
	mkdir -p $(OBJ_DIR)

$(NAME)	: $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	rm -rf $(NAME)