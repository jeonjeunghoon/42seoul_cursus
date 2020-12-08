NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

LIBC		=	ar rc

SRCS		=	./libft/ft_strlen.c \
				./libft/ft_atoi.c \
				./libft/ft_itoa.c \
				./libft/ft_putchar_fd.c \
				./libft/ft_putstr_fd.c \
				./libft/ft_putnbr_fd.c \
				./ft_printf.c \
				./ft_leftzero.c \
				./ft_numlen.c \
				./ft_except.c \
				./ft_width.c \
				./ft_precision.c \
				./ft_free.c \
				./ft_itob.c \
				./ft_leftflag.c \
				./ft_printflag.c \
				./ft_print_zero.c \
				./ft_print_left.c \
				./ft_print_alpha.c \
				./ft_print_num.c \
				./ft_structclear.c \
				./ft_get_size.c \
				./ft_globalclear.c

OBJS		=	${SRCS:.c=.o}
INCS		=	.

.c.o:
				${CC} ${CFLAGS} -c $< -o $(<:.c=.o) -I${INCS}

$(NAME):		${OBJS}
				${LIBC} ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME} ${bonus}

re:				fclean all