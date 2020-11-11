/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/11 17:40:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			format_specifier(char *format, va_list ap)
{
	
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = 0;
	while (*format)
	{
		if (*format == '%')
			res = format_specifier(format, ap);
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
