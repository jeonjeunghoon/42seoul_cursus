NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

LIBC		=	ar rc

SRCS		=	ft_printf.c \
				sources/ft_strlen.c \
				sources/ft_atoi.c \
				sources/ft_itoa.c \
				sources/ft_putchar_fd.c \
				sources/ft_putstr_fd.c \
				sources/ft_putnbr_fd.c \
				sources/ft_leftzero.c \
				sources/ft_numlen.c \
				sources/ft_except.c \
				sources/ft_width.c \
				sources/ft_precision.c \
				sources/ft_free.c \
				sources/ft_itob.c \
				sources/ft_leftflag.c \
				sources/ft_printflag.c \
				sources/ft_print_zero.c \
				sources/ft_print_left.c \
				sources/ft_print_alpha.c \
				sources/ft_print_num.c \
				sources/ft_structclear.c \
				sources/ft_get_size.c \
				sources/ft_globalclear.c

OBJS		=	${SRCS:.c=.o}
INCS		=	-I include/ft_printf.h

.c.o:
				${CC} ${CFLAGS} -c $< -o $(<:.c=.o) ${INCS}

$(NAME):		${OBJS}
				${LIBC} ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all