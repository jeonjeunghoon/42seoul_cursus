/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/13 15:43:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		is_flag(char *format, va_list ap)
{
	
}

int			format_specifier(char *format, va_list ap, int res)
{
	if (*format == 'c')
		write(1, ap, 1);
	if (*format == 's')
		write(1, ap, ft_strlen(ap));
	if (*format == 'p')
		//
	if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_putnbr_fd(ft_atoi(ap, *format), 1);
	if (*format == 'x' || *format == 'X')
		ft_putnbr_base(ft_atoi(ap, *format), "16");
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = 0;
	while (*format)
	{
		is_flag(format, ap);
		if (*format == '%')
		{
			format++;
			res = format_specifier(format, ap, res);
		}
		else 
		{
			write(1, format, 1);
			res++;
			format++;
		}
	}
	va_end(ap);
	return (res);
}

int main()
{
	printf("out: %d\n", printf("hello\n"));
	printf("OUT: %d\n", ft_printf("HELLO\n"));
	// printf("%c", 'a');
}
