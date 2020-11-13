/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/13 23:24:12 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t		ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (((unsigned char *)s)[res])
		res++;
	return (res);
}

// void		is_flag(char *format, va_list ap)
// {
	
// }

void		format_specifier(const char *format, va_list ap, int res)
{
	char	*s;

	if (*format == 'c' || *format == 's')
		s = va_arg(ap, char *);
	else if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X')
		s = ft_itoa(va_arg(ap, int));
	if (*format == 'c')
		write(1, s, 1);
	if (*format == 's')
		write(1, s, ft_strlen(s));
	// if (*format == 'p')
	if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_putnbr_fd(ft_atoi(s, *format), 1);
	if (*format == 'x')
		ft_putnbr_base(ft_atoi(s, *format), "0123456789abcdef");
	if (*format == 'X')
		ft_putnbr_base(ft_atoi(s, *format), "0123456789ABCDEF");
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
			format_specifier(format, ap, res);
		}
		else 
		{
			write(1, format, 1);
			res++;
		}
		format++;
	}
	va_end(ap);
	return (res);
}

int main()
{
	char s[] = "HELLO";
	
	// printf("out: %d\n", printf("hello\n"));
	ft_printf("OUT: %x\n", 1000);
}
