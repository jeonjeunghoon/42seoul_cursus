CC = gcc
CFLAGS = -Wall -Werror -Wextra
MV = mv

NAME = cub3D

SRCS_NAME = main.c parsing_init.c texture_init.c screen_init.c player_init.c \
			ft_raycasting.c ft_minimap.c ft_sprite.c ft_render.c ft_key.c \
			ft_bmp.c get_next_line.c parse_map.c check_map.c\
			utility.c utility2.c utility3.c utility4.c

SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

LIB_NAME = ft
LIB_DIR = ./libft

MLX_NAME = mlx
MLX_DIR = ./opengl

MLXBETA_NAME = mlxbeta
MLXBETA_DIR = ./mms

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(MLXBETA_DIR)
	$(MV) $(MLXBETA_DIR)/libmlxbeta.dylib ./libmlxbeta.dylib
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) \
	-L$(MLX_DIR) -l$(MLX_NAME) -L . -l$(MLXBETA_NAME) \
	-framework OpenGL -framework Appkit -lz $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLXBETA_DIR) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@

.PHONY: all clean fclean

all : $(NAME) cub.map

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(MLXBETA_DIR) clean
	rm -rf $(OBJS)
	rm -rf bmp/cub3d.bmp

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(MLXBETA_DIR) clean
	rm -rf libmlxbeta.dylib
	rm -rf $(NAME) $(OBJS)
	rm -rf bmp/cub3d.bmp

re : fclean all

bonus : $(NAME)
