# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 20:00:42 by jeunjeon          #+#    #+#              #
#    Updated: 2021/11/05 04:03:56 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =				gcc
CFLAGS =			#-Wall -Wextra -Werror

NAME =				so_long
BONUS =				so_long

MAP_NAME =			map.ber
MAP_PATH =			./map
MAP =				$(addprefix $(MAP_PATH)/, $(MAP_NAME))

SRCS_NAME = 		main.c \
					exception.c \
					game_init.c \
					assets_parsing.c \
					ft_key.c \
					so_long.c \
					utility.c \
					get_next_line.c

SRCS_PATH =			./srcs
SRCS =				$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME =			$(SRCS_NAME:.c=.o)
OBJS_PATH =			./objs
OBJS =				$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

SRCS_BONUS_NAME =	main_bonus.c \
					exception_bonus.c \
					game_init_bonus.c \
					assets_parsing_bonus.c \
					ft_key_bonus.c \
					enemy_bonus.c \
					so_long_bonus.c \
					utility_bonus.c \
					get_next_line_bonus.c

SRCS_BONUS_PATH =	./srcs_bonus
SRCS_BONUS =		$(addprefix $(SRCS_BONUS_PATH)/, $(SRCS_BONUS_NAME))

OBJS_BONUS_NAME =	$(SRCS_BONUS_NAME:.c=.o)
OBJS_BONUS_PATH =	./objs_bonus
OBJS_BONUS =		$(addprefix $(OBJS_BONUS_PATH)/, $(OBJS_BONUS_NAME))

INC_PATH =			./inc
INC_BONUS_PATH =	./inc_bonus

LIB_NAME =			ft
LIB_PATH =			./libft

MLX_NAME =			mlx
MLX_PATH =			./mlx

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_PATH) all
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) \
	-L$(LIB_PATH) -l$(LIB_NAME) \
	-L$(MLX_PATH) -l$(MLX_NAME) \
	-framework OpenGL -framework Appkit -lz $^ -o $@

$(BONUS) : $(OBJS_BONUS)
	$(MAKE) -C $(LIB_PATH) all
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) \
	-L$(LIB_PATH) -l$(LIB_NAME) \
	-L$(MLX_PATH) -l$(MLX_NAME) \
	-framework OpenGL -framework Appkit -lz $^ -o $@

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

$(OBJS_BONUS_PATH)/%.o : $(SRCS_BONUS_PATH)/%.c
	mkdir $(OBJS_BONUS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC_BONUS_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

.PHONY: all bonus clean fclean

all : $(NAME)

bonus : $(BONUS) $(OBJS_BONUS)

clean :
	$(MAKE) -C $(LIB_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(bonus)

re : fclean all

		
