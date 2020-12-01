/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/01 12:40:26 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			print_arg(char *format, char **ptr_arg, long long ld)
{
	if (*format == 's' || *format == 'x' || *format == 'X' || *format == 'p')
	{
		if (*format == 'p')
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(*ptr_arg, 1);
		if ((*format == 'x' || *format == 'X' || *format == 'p') &&
		*ptr_arg != NULL && **ptr_arg != 0)
		{
			free(*ptr_arg);
			**ptr_arg = 0;
		}
	}
	else if (*format == 'c' || *format == '%')
		ft_putchar_fd(ld, 1);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_putnbr_fd(ld, 1);
}

void			get_arg(char *format, va_list ap, char **ptr_arg)
{
	ld = 0;
	if (*format == 'c' || *format == 'd' || *format == 'i' || *format == 'u')
		ld = va_arg(ap, int);
	else if (*format == 's')
		*ptr_arg = va_arg(ap, char *);
	else if (*format == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", ptr_arg);
	else if (*format == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", ptr_arg);
	else if (*format == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", ptr_arg);
	else if (*format == '%')
		ld = '%';
	if (*format == 's' || *format == 'x' || *format == 'X' || *format == 'p')
	{
		arg_len = ft_strlen(*ptr_arg);
		if (*format == 'p')
			arg_len += 2;
	}
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		arg_len = ft_digitlen(ld);
	else if (*format == 'c' || *format == '%')
		arg_len = 1;
}

// void			flag_control(char *format)
// {
	
// }

int				ft_printf(const char *format, ...)
{
	char		*ptr_arg;
	va_list 	ap;

	va_start(ap, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			arg_len = 0;
			// flag_control((char *)(++format));
			get_arg((char *)(++format), ap, &ptr_arg);
			print_arg((char *)format, &ptr_arg, ld);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	return (g_count);
}

int main(void)
{
	printf("out: %d\n", printf("out: %d\n", -2100000000));
	ft_printf("OUT: %d\n", ft_printf("OUT: %d\n", -2100000000));
}

/*
	생각하는 구현 로직
	전역변수 arg_len에 플래그 출력갯수를 저장,
*/