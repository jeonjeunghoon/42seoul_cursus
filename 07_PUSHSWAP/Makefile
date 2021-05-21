# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:22:16 by jeunjeon          #+#    #+#              #
#    Updated: 2021/05/21 11:26:49 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = srcs/*.c
OBJS = $(SRCS:.o=.c)
INC = inc/*.h

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC) $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(SRCS) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re