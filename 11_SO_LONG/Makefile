# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 20:00:42 by jeunjeon          #+#    #+#              #
#    Updated: 2021/11/03 03:55:05 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

NAME = so_long

MAP_NAME = map.ber
MAP_PATH = ./map
MAP = $(addprefix $(MAP_PATH)/, $(MAP_NAME))

SRCS_NAME = main.c \
			exception.c \
			game_init.c \
			assets_parsing.c \
			start_game.c \
			end_game.c \
			utility.c \
			get_next_line.c

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH = ./inc

LIB_NAME = ft
LIB_PATH = ./libft

MLX_NAME = mlx
MLX_PATH = ./mlx

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_PATH) all
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) \
	-L$(LIB_PATH) -l$(LIB_NAME) \
	-L$(MLX_PATH) -l$(MLX_NAME) \
	-framework OpenGL -framework Appkit -lz $^ -o $@

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

.PHONY: all clean fclean

all : $(NAME) $(MAP)

clean :
	$(MAKE) -C $(LIB_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)
