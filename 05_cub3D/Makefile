ARCH = arch -x86_64
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
MV = mv

NAME = cub3d

SRCS_NAME = main.c ft_screen.c key.c utility.c utility2.c ft_raycasting.c player.c ft_texture.c ft_sprite.c
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

fclean :
	$(ARCH) $(MAKE) -C $(LIB_DIR) fclean
	$(ARCH) $(MAKE) -C $(MLX_DIR) clean
	$(ARCH) $(MAKE) -C $(MLXBETA_DIR) clean
	rm -rf libmlxbeta.dylib
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : $(NAME)