/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 13:52:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t		ft_strlen(char *s)
{
	int		res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

// void		is_flag(char *format, va_list ap)
// {
	
// }

int			format_specifier(const char *format, va_list ap, int temp)
{
	char	*s;
	char	c;

	if (*format == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		return (1);
	}
	if (*format == 's')
		s = va_arg(ap, char *);
	else if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		s = ft_itoa(va_arg(ap, int));
	else if (*format == 'u')
		s = ft_utoa(va_arg(ap, unsigned int));
	if (*s)
		temp = ft_strlen(s);
	if (*format == 's')
		write(1, s, temp);
	// if (*format == 'p')
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(ft_atoi(s), 1);
	else if (*format == 'u')
		ft_putnbr_fd(ft_atou(s), 1);
	else if (*format == 'x')
		ft_putnbr_base(ft_atoi(s), "0123456789abcdef");
	else if (*format == 'X')
		ft_putnbr_base(ft_atoi(s), "0123456789ABCDEF");
	return (temp);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = 0;
	while (*format)
	{
		// is_flag((char *)format, ap);
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, "%", 1);
				format++;
				res++;
			}
			else if (*format == 'c' || *format == 's' || *format == 'p' ||
			*format == 'd' || *format == 'i' || *format == 'u' ||
			*format == 'x' || *format == 'X')
				res += format_specifier(format++, ap, res);
			else
			{
				va_end(ap);
				return (0);
			}
		}
		else
		{
			write(1, format++, 1);
			res++;
		}
	}
	va_end(ap);
	return (res);
}

int main()
{
	char s[] = "HELLO";

	printf("out : %d\n", printf("out : %u\n", -1));
	ft_printf("OUT : %d\n", ft_printf("OUT : %u\n", -1));
}

/*
	서식지정자 u에 음수를 넣었을 경우 잘못된 동작을 함
	서식지정자 x,X에 음수를 넣었을 경우 잘못된 동작을 함 
*/