/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:53:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				get_flag(const char **ppf, va_list ap)
{
	*ppf += 1;
	ft_leftzero(ppf);
	ft_width(ppf, ap, **ppf);
	ft_precision(ppf, ap, **ppf);
}

void				get_arg(const char f, va_list ap, char **pp)
{
	if (f == 'd' || f == 'i' || f == 'u' || f == 'c')
		g_lst.n = va_arg(ap, int);
	else if (f == 's')
		*pp = va_arg(ap, char *);
	else if (f == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", pp, f);
	else if (f == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", pp, f);
	else if (f == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", pp, f);
	else if (f == '%')
		g_lst.n = '%';
	else
		g_error = -1;
	ft_get_size(f, *pp);
}

void				print_arg(const char f, char *p)
{
	if (f == 's' || f == 'x' || f == 'X' || f == 'p')
	{
		if (p == NULL)
		{
			write(1, "(null)", g_arglen);
			g_count += g_arglen;
		}
		else if (f == 'p')
		{
			ft_putstr_fd("0x", 1);
			if (p != NULL && g_arglen != 2)
				ft_putstr_fd(p, 1);
		}
		else if ((size_t)g_arglen == ft_strlen(p))
			ft_putstr_fd(p, 1);
		else if ((size_t)g_arglen != ft_strlen(p))
		{
			write(1, p, g_arglen);
			g_count += g_arglen;
		}
	}
	else if (f == 'c' || f == '%')
		ft_putchar_fd(g_lst.n, 1);
	else if ((f == 'd' || f == 'i' || f == 'u') && g_arglen)
		ft_putnbr_fd(g_lst.n, 1, f, g_lst.minus);
}

int					ft_printf(const char *format, ...)
{
	char			*p;
	va_list			ap;

	ft_globalclear();
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			get_flag(&format, ap);
			get_arg(*format, ap, &p);
			if (g_error == -1)
				return (g_count);
			ft_leftflag(*format);
			print_arg(*format, p);
			ft_printflag(*format);
			ft_structclear();
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	ft_free(*format, (void **)&p);
	va_end(ap);
	return (g_count);
}
