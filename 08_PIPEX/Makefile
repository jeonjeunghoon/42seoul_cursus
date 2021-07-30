# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 18:28:22 by jeunjeon          #+#    #+#              #
#    Updated: 2021/07/30 18:34:49 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	pipex
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS_NAME			=	main.c \
						arg_init.c \
						redirect.c \
						connect_pipe.c

SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_LINK			=	-I./inc
LIBFT				=	-L./lib/libft -lft

$(NAME)				:	$(OBJS)
						@$(MAKE) -C ./lib/libft all
						$(CC) $(CFLAGS) $(OBJS) $(INC_LINK) $(LIBFT) -o $@

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						@mkdir $(OBJS_PATH) 2> /dev/null || true
						$(CC) $(CFLAGS) $(INC_LINK) -c $< -o $@

all					:	$(NAME)

clean				:
						@$(MAKE) -C ./lib/libft clean
						rm -rf $(OBJS)
fclean				:
						@$(MAKE) -C ./lib/libft fclean
						rm -rf $(OBJS)
						rm -rf $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
