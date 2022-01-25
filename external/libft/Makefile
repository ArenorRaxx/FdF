# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:34:58 by brhajji-          #+#    #+#              #
#    Updated: 2022/01/25 19:54:37 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs/
SRCS = ft_strlen.c\
	   ft_isalpha.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strtrim.c\
	   ft_strjoin.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c
BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

OBJS = ${SRCS:.c=.o}
BONUSOBJ = ${BONUS:.c=.o}
HEAD = ./ 
NAME = libft.a
CC = gcc -Wall -Werror -Wextra
RM = rm -f
.c.o:	
	${CC} -I ${HEAD} -c $< -o ${<:.c=.o}
${NAME}: ${OBJS}	
	ar rc ${NAME} ${OBJS}
all : ${NAME}
bonus: ${BONUSOBJ} ${OBJS}
	ar rc ${NAME} ${BONUSOBJ}
clean :
	${RM} ${OBJS} ${BONUSOBJ}
fclean : clean	
	${RM} ${NAME} 
re : fclean all
.PHONY : all bonus clean fclean re
