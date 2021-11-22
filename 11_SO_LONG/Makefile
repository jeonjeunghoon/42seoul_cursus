# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 16:44:07 by jeunjeon          #+#    #+#              #
#    Updated: 2021/11/20 16:44:26 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =				gcc
CFLAGS =			-Wall -Wextra -Werror

NAME =				so_long

SRCS_NAME = 		main.c \
					exception.c \
					game_init.c \
					assets_parsing.c \
					ft_key.c \
					so_long.c \
					utility.c \
					get_next_line.c\
					draw_init.c\
					draw_set_cam.c\
					draw_sprites1.c\
					draw_sprites2.c

BSRCS_NAME =		main_bonus.c \
					exception_bonus.c \
					game_init_bonus.c \
					assets_parsing_bonus.c \
					ft_key_bonus.c \
					so_long_bonus.c \
					utility_bonus.c \
					get_next_line_bonus.c\
					draw_init_bonus.c\
					enemy_bonus.c\
					draw_set_cam_bonus.c\
					draw_sprites1_bonus.c\
					draw_sprites2_bonus.c

SRCS_PATH =			./srcs
SRCS =				$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME =			$(SRCS_NAME:.c=.o)
OBJS_PATH =			./objs
OBJS =				$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

BSRCS_PATH =		./srcs_bonus
BSRCS =				$(addprefix $(BSRCS_PATH)/, $(BSRCS_NAME))

BOBJS_NAME =		$(BSRCS_NAME:.c=.o)
BOBJS_PATH =		./objs_bonus
BOBJS =				$(addprefix $(BOBJS_PATH)/, $(BOBJS_NAME))

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

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir $(OBJS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

$(BOBJS_PATH)/%.o : $(BSRCS_PATH)/%.c
	mkdir $(BOBJS_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -c $< -o $@

.PHONY: all clean fclean

all : $(NAME)

bonus : $(BOBJS)
	$(MAKE) -C $(LIB_PATH) all
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) \
	-L$(LIB_PATH) -l$(LIB_NAME) \
	-L$(MLX_PATH) -l$(MLX_NAME) \
	-framework OpenGL -framework Appkit -lz $^ -o so_long

clean :
	$(MAKE) -C $(LIB_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
