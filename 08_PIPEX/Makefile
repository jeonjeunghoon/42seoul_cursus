# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 16:39:55 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/17 16:45:54 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror

NAME	=	pipex
SRCS	=	srcs/main.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all		:	$(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean all

.PHONY	:	all, clean, fclean, re