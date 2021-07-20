# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 16:39:55 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/18 22:21:14 by jeunjeon         ###   ########.fr        #
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

INC_LINK		=	-I./inc
LIBFT			=	-L./lib/libft -lft

$(NAME)			:	$(OBJ) libft
					$(CC) $(FLAGS) $(OBJ) $(INC_LINK) $(LIBFT) -o $(NAME) 

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c
					@mkdir $(OBJ_PATH) 2> /dev/null || true
					$(CC) $(FLAGS) $(INC_LINK) -o $@ -c $<

libft			:
					@$(MAKE) -C ./lib/libft all

all				:	$(NAME)

clean			:
					@$(MAKE) -C ./lib/libft clean
					rm -rf $(OBJ)
fclean			:
					@$(MAKE) -C ./lib/libft fclean
					rm -rf $(OBJ)
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
