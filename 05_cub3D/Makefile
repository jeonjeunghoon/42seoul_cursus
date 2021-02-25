CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = cub3d

SRCS_NAME = main.c key.c utility.c render.c player.c
SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -L$(MLX_DIR) -l$(LIB_NAME) -l$(MLX_NAME) -framework OpenGL -framework Appkit -o $(NAME) $^

.PHONY: all clean fclean

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : $(NAME)