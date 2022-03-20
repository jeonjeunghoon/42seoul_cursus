# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:19:40 by jeunjeon          #+#    #+#              #
#    Updated: 2022/03/20 11:24:43 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minishell
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror

SRCS_NAME			=	main.c \
						ft_prompt.c \
						ft_parsing.c \
						check_stream_symbol.c \
						symbol_error_utility.c \
						check_symbol_utility.c \
						check_symbol_utility2.c \
						ft_signal.c \
						minishell.c \
						create_argv_set.c \
						create_argv_set2.c \
						ft_command.c \
						ft_echo.c \
						ft_cd.c \
						ft_pwd.c \
						ft_export.c \
						export_utility.c \
						ft_unset.c \
						unset_utility.c \
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
						command_utility.c \
						command_utility2.c \
						exe_cmd.c \
						w_utility.c \
						redirect_utility.c \
						ft_wildcard.c\
						ft_wildcard2.c\
						ft_wildcard3.c

SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH			=	./inc

LIBFT_NAME			=	ft
LIBFT_PATH			=	./libft

RL_NAME				=	readline
RL_PATH				=	$(shell brew --prefix readline)/lib

RL_INC				=	$(shell brew --prefix readline)/include

$(NAME)				:	$(OBJS)
						@$(MAKE) -C $(LIBFT_PATH) bonus
						$(CC) $(CFLAGS) $(OBJS) -I$(INC_PATH) -I$(RL_INC) -l$(LIBFT_NAME) -L$(LIBFT_PATH) -l$(RL_NAME) -L$(RL_PATH) -o $@

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						mkdir $(OBJS_PATH) 2> /dev/null || true
						$(CC) $(CFLAGS) -I$(INC_PATH) -I$(RL_INC) -c $< -o $@

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
