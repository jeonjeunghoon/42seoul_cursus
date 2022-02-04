# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:19:40 by jeunjeon          #+#    #+#              #
#    Updated: 2022/02/04 16:09:12 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell
CC					=	gcc
CFLAGS				=	# -Wall -Wextra -Werror
LINKING_FLAGS		=	-lreadline -L/opt/homebrew/opt/readline/lib
COMFILE_FLAGS		=	-I/opt/homebrew/opt/readline/include

SRCS_NAME			=	main.c \
						ft_prompt.c \
						ft_parsing.c \
						ft_signal.c \
						minishell.c \
						ft_echo.c \
						ft_cd.c \
						ft_pwd.c \
						ft_export.c \
						ft_unset.c \
						ft_env.c \
						ft_exit.c \
						ft_error.c \
						utility.c \
						parse_utility.c \
						parse_utility2.c \
						tokenize.c \
						tokenize_utility.c \
						tokenize_utility2.c \
						tokenize_utility3.c \
						stream_utility.c \
						stream_utility2.c \
						command_utility.c \
						export_utility.c
SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH			=	./inc

LIBFT_NAME			=	ft
LIBFT_PATH			=	./libft

$(NAME)				:	$(OBJS)
						@$(MAKE) -C $(LIBFT_PATH) bonus
						$(CC) $(CFLAGS) $(OBJS) -I$(INC_PATH) -L$(LIBFT_PATH) -l$(LIBFT_NAME) $(LINKING_FLAGS) -o $@

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						mkdir $(OBJS_PATH) 2> /dev/null || true
						$(CC) $(CFLAGS) -I$(INC_PATH) $(COMFILE_FLAGS) -c $< -o $@

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