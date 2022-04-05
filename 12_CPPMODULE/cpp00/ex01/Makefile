# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 17:03:30 by jeunjeon          #+#    #+#              #
#    Updated: 2022/04/05 13:26:29 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
CFLAGS	=	# -Wall -Wextra -Werror

INC		=	.
SRCS	=	main.cpp \
			Phonebook.cpp \
			Contact.cpp
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
