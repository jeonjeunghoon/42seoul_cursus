/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/30 16:53:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void		ft_flag(char *format, va_list ap)
// {
	
// }

void		ft_specifier(char *fm, va_list ap, char *s)
{
	if (*fm == ' ' && g_flag++ == 0)
	{
		while (*fm == ' ')
		{
			g_move++;
			fm++;
		}
	}
	if (*fm == 'c' || *fm == 's' || *fm == 'd' || *fm == 'i' || *fm == 'u')
		ft_spec_csdiu(*fm, ap, s);
	else if (*fm == 'p' || *fm == 'x' || *fm == 'X' || *fm == '%')
		ft_spec_pxp(*fm, ap, s);
	else
		return ;
}

int			ft_printf(const char *format, ...)
{
	char	*s;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			g_move = 0;
			g_flag = 0;
			ft_specifier((char *)++format, ap, s);
			format += g_move;
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (g_count);
}

int main()
{
	char s[] = "Hello";

	printf("out: %d\n", printf("out:%u\n", 11111111111111111111));
	ft_printf("OUT: %d\n", ft_printf("OUT:%u\n", 11111111111111111111));
	// printf("out: %    d\n", 123);
	// ft_printf("OUT: %    d\n", 123);
}