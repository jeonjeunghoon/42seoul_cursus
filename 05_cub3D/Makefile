ARCH = arch -x86_64
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
MV = mv

NAME = cub3D

SRCS_NAME = main.c ft_screen.c ft_key.c ft_raycasting.c ft_player.c ft_texture.c ft_sprite.c ft_minimap.c ft_bmp.c ft_parsing.c utility.c utility2.c get_next_line.c
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
	$(ARCH) $(MAKE) -C $(LIB_DIR) bonus
	$(ARCH) $(MAKE) -C $(MLX_DIR)
	$(ARCH) $(MAKE) -C $(MLXBETA_DIR)
	$(MV) $(MLXBETA_DIR)/libmlxbeta.dylib ./libmlxbeta.dylib
	$(ARCH) $(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) -L . -l$(MLXBETA_NAME) -framework OpenGL -framework Appkit -lz $^ -o $@
	./$(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(ARCH) $(CC) $(CFLAGS) -I$(MLXBETA_DIR) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@

.PHONY: all clean fclean

all : $(NAME)

clean :
	$(ARCH) $(MAKE) -C $(LIB_DIR) clean
	$(ARCH) $(MAKE) -C $(MLX_DIR) clean
	$(ARCH) $(MAKE) -C $(MLXBETA_DIR) clean
	rm -rf $(OBJS)
	rm -rf bmp/cub3d.bmp

fclean :
	$(ARCH) $(MAKE) -C $(LIB_DIR) fclean
	$(ARCH) $(MAKE) -C $(MLX_DIR) clean
	$(ARCH) $(MAKE) -C $(MLXBETA_DIR) clean
	rm -rf libmlxbeta.dylib
	rm -rf $(NAME) $(OBJS)
	rm -rf bmp/cub3d.bmp

re : fclean all

bonus : $(NAME)