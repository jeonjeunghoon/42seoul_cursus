# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 16:39:55 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/18 21:14:33 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	gcc
CFLAGS			=	#-Wall -Wextra -Werror

SRC_NAME		=	main.c
SRC_PATH		=	./srcs
SRC				=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH		=	./objs
OBJ				=	$(addprefix $(OBJ_PATH)/, $(SRC_NAME:%.c=%.o))

vpath %.c \
	$(SRC_PATH)

INC_LINK		=	-I./incs
LIBFT			=	-L./lib/libft -lft

$(OBJ_PATH)/%.o	:	%.c | $(OBJ_PATH)
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS) libft
					$(CC) $(CFLAGS) $(OBJ) $(INC_LINK) $(LIBFT) -o $(NAME)


# libft complile
libft			:
					@$(MAKE) -C ./lib/libft all

all				:	$(NAME)

clean			:
					@$(MAKE) -C ./lib/libft clean
					@rm -rf ./obj

fclean			:
					@$(MAKE) -C ./lib/libft clean
					@rm -rf ./obj $(NAME)

re				:	fclean all

.PHONY			:	all, clean, fclean, re
