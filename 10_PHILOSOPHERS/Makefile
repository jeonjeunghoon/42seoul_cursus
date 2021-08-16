# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 17:05:04 by jeunjeon          #+#    #+#              #
#    Updated: 2021/08/16 21:53:21 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo
CC					=	gcc
CFLAGS				=	-g -fsanitize=address #-Wall -Wextra -Werror

SRCS_NAME			=	main.c \
						init.c \
						philo_func.c \
						philo_act.c \
						time_func.c \
						ft_isdigit.c \
						ft_atoi.c

SRCS_PATH			=	./srcs
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME			=	$(SRCS_NAME:.c=.o)
OBJS_PATH			=	./objs
OBJS				=	$(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INC_PATH			=	./inc

$(NAME)				:	$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -I$(INC_PATH) -o $@

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.c
						mkdir $(OBJS_PATH) 2> /dev/null || true
						$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

all					:	$(NAME)

clean				:
						rm -rf $(OBJS)

fclean				:	clean
						rm -rf $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
