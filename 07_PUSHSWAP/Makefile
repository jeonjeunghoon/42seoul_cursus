# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 11:22:16 by jeunjeon          #+#    #+#              #
#    Updated: 2021/05/24 20:34:31 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror

NAME		=	push_swap
LIB_NAME	=	libpush_swap.a
LIBC		=	ar rc
SRCS		=	srcs/libft/ft_memset.c \
				srcs/libft/ft_bzero.c \
				srcs/libft/ft_memcpy.c \
				srcs/libft/ft_memccpy.c \
				srcs/libft/ft_memmove.c \
				srcs/libft/ft_memchr.c \
				srcs/libft/ft_memcmp.c \
				srcs/libft/ft_strlen.c \
				srcs/libft/ft_strlcpy.c \
				srcs/libft/ft_strlcat.c \
				srcs/libft/ft_strchr.c \
				srcs/libft/ft_strrchr.c \
				srcs/libft/ft_strnstr.c \
				srcs/libft/ft_strncmp.c \
				srcs/libft/ft_strncmp.c \
				srcs/libft/ft_atoi.c \
				srcs/libft/ft_isalpha.c \
				srcs/libft/ft_isdigit.c \
				srcs/libft/ft_isalnum.c \
				srcs/libft/ft_isascii.c \
				srcs/libft/ft_isprint.c \
				srcs/libft/ft_toupper.c \
				srcs/libft/ft_tolower.c \
				srcs/libft/ft_calloc.c \
				srcs/libft/ft_strdup.c \
				srcs/libft/ft_substr.c \
				srcs/libft/ft_strjoin.c \
				srcs/libft/ft_strtrim.c \
				srcs/libft/ft_split.c \
				srcs/libft/ft_itoa.c \
				srcs/libft/ft_strmapi.c \
				srcs/libft/ft_putchar_fd.c \
				srcs/libft/ft_putstr_fd.c \
				srcs/libft/ft_putendl_fd.c \
				srcs/libft/ft_putnbr_fd.c \
				srcs/libft/ft_lstnew.c \
				srcs/libft/ft_lstadd_front.c \
				srcs/libft/ft_lstsize.c \
				srcs/libft/ft_lstlast.c \
				srcs/libft/ft_lstadd_back.c \
				srcs/libft/ft_lstdelone.c \
				srcs/libft/ft_lstclear.c \
				srcs/libft/ft_lstiter.c \
				srcs/libft/ft_lstmap.c

OBJS	=		$(SRCS:.c=.o)
INCS	=		inc

.c.o		:	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(LIB_NAME)	:	$(OBJS)
				$(LIBC) $(LIB_NAME) $(OBJS)

all			:	$(LIB_NAME)

clean		:
				rm -rf $(OBJS) $(NAME)

fclean		:	clean
				rm -rf $(LIB_NAME)

re			:	fclean all

pushswap	:	
				$(CC) $(CFLAGS) srcs/main.c -o $(NAME) $(LIB_NAME)

.PHONY		:	all, clean, fclean, re, pushswap