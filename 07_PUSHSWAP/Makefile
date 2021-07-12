# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:22:16 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/12 17:27:03 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap
SRCS		=	srcs/main.c \
				srcs/utility.c \
				srcs/utility2.c \
				srcs/utility3.c \
				srcs/ft_strdup.c \
				srcs/ft_split.c \
				srcs/ft_atoi.c \
				srcs/pushswap_func.c \
				srcs/pushswap_func2.c \
				srcs/pushswap_func3.c \
				srcs/arg_except.c \
				srcs/find_pivot.c \
				srcs/a_to_b.c \
				srcs/b_to_a.c \
				srcs/a_except.c \
				srcs/b_except.c

OBJS	=		$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all, clean, fclean, re
