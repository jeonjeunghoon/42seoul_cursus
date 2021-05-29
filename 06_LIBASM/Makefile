# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 23:47:20 by jeunjeon          #+#    #+#              #
#    Updated: 2021/05/29 19:10:59 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

NASM = nasm
NASM_FLAGS = -f macho64

NAME = libasm.a

SRCS =	srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_write.s \
		srcs/ft_read.s \
		srcs/ft_strdup.s
OBJS = $(SRCS:.s=.o)
INC = libasm.h

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.s
	$(NASM) -I $(INC) $(NASM_FLAGS) $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME) test

re: fclean all

test: re
	$(CC) $(C_FLAGS) main.c -o test -L. -lasm
	./test

.PHONY: all, clean, fclean, re
