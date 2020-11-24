/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:52:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 20:09:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void		ft_flag(char *format, va_list ap)
// {
	
// }

void		ft_specifier(char *fm, va_list ap, char *s)
{
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
	g_count = 0;
	while (*format)
	{
		if (*format == '%')
			ft_specifier((char *)(++format), ap, s);
		else
		{
			write(1, format, 1);
			g_count++;
		}
		format++;
	}
	va_end(ap);
	return (g_count);
}

int main()
{
	char s[] = "HELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLO";

	printf("out: %d\n", printf("out: %p\n", s));
	ft_printf("OUT: %d\n", ft_printf("OUT: %p\n", s));
}
