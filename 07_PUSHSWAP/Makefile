# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:22:16 by jeunjeon          #+#    #+#              #
#    Updated: 2021/06/29 17:20:44 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror

NAME		=	push_swap
SRCS		=	srcs/main.c \
				srcs/utility.c \
				srcs/utility2.c \
				srcs/ft_atoi.c \
				srcs/pushswap_func.c \
				srcs/pushswap_func2.c \
				srcs/pushswap_func3.c \
				srcs/find_pivot.c \
				srcs/push_swap.c

OBJS	=		$(SRCS:.c=.o)
INCS	=		inc

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all, clean, fclean, re