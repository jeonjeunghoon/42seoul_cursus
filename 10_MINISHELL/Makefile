# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:19:40 by jeunjeon          #+#    #+#              #
#    Updated: 2021/10/19 15:25:08 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell
CC					=	gcc
CFLAGS				=	# -Wall -Wextra -Werror

SRCS_NAME			=	main.c
SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH			=	./inc

LIBFT_NAME			=	ft
LIBFT_PATH			=	./libft

$(NAME)				:	$(OBJS)
						@$(MAKE) -C $(LIBFT_PATH) all
						$(CC) $(CFLAGS) $(OBJS) -I$(INC_PATH) -L$(LIBFT_PATH) -l$(LIBFT_NAME) -lreadline -o $@

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						mkdir $(OBJS_PATH) 2> /dev/null || true
						$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all					:	$(NAME)

clean				:
						@$(MAKE) -C $(LIBFT_PATH) clean
						rm -rf $(OBJS)

fclean				:
						@$(MAKE) -C $(LIBFT_PATH) fclean
						rm -rf $(OBJS)
						rm -rf $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re