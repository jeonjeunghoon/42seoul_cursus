# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 21:25:37 by jeunjeon          #+#    #+#              #
#    Updated: 2022/04/09 21:26:59 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Account
CC		=	c++
CFLAGS	=	#-Wall -Wextra -Werror

INC		=	.
SRCS	=	Account.cpp \
			tests.cpp
OBJS	=	$(SRCS:.cpp=.o)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -I$(INC) $(OBJS) -o $@

all		:	$(NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)
			
re		:	fclean all

.PHONY	:	all clean fclean re
