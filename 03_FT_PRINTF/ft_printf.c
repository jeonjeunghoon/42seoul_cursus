/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/23 20:03:03 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void		is_flag(char *format, va_list ap)
// {
	
// }

void		format_specifier(char *fm, va_list ap)
{
	char	*s;
	char	c;

	if (*fm == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		count++;
	}
	if (*fm == 's')
		s = va_arg(ap, char *);
	else
		s = ft_itoa(va_arg(ap, int), *fm);
	if (*fm == 's')
		write(1, s, ft_strlen(s));
	else if (*fm == 'd' || *fm == 'i' || *fm == 'u')
		ft_putnbr_fd(ft_atoi(s, *fm), 1);
	else if (*fm == 'p' || *fm == 'x' || *fm == 'X')
		ft_putnbr_base(ft_atoi(s, *fm), "0123456789abcdef", *fm);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		// is_flag((char *)format, ap);
		if (*format == '%')
		{
			format++;
			if (*format == '%' && *format)
			{
				write(1, format++, 1);
				count++;
			}
			else if (*format == 'c' || *format == 's' || *format == 'p' ||
			*format == 'd' || *format == 'i' || *format == 'u' ||
			*format == 'x' || *format == 'X')
				format_specifier((char *)format++, ap);
			else
				break ;
		}
		else
		{
			write(1, format++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}

int main()
{
	char s[] = "HELLO";

	printf("out : %d\n", printf("out : %p\n", s));
	ft_printf("OUT : %d\n", ft_printf("OUT : %p\n", s));
}
