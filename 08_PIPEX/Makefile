# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 16:39:55 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/18 20:21:42 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	gcc
CFLAGS			=	#-Wall -Wextra -Werror

SRC_NAME		=	main.c
SRC_PATH		=	./srcs
SRC				=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME		=	$(SRC_NAME:.c=.o)
OBJ_PATH		=	./objs
OBJ				=	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC_LINK		=	-I./incs
LIBFT			=	-L./lib/libft -lft

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c
					gcc $(FLAGS) $(INC_LINK) -o $@ -c $<

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
