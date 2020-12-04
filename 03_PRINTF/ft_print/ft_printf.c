/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 16:39:56 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_flag_value(const char **pp_fm)
{
	if (*(*pp_fm - 1) == '.')
	{
		while (**pp_fm == '0')
			*pp_fm += 1;
		if ((*(*pp_fm - 1) == '0') && !(**pp_fm >= '1' && **pp_fm <= '9'))
			flst.pre = -1;
		else
		{
			flst.pre = ft_atoi(*pp_fm, 'd');
			*pp_fm += ft_dlen(flst.pre) - 1;
		}
	}
	else
	{
		flst.width = ft_atoi(*pp_fm, 'd');
		*pp_fm += ft_dlen(flst.width) - 1;
	}
}

void			get_flag(const char **pp_fm, va_list ap)
{
	while (**pp_fm == '-' || **pp_fm == '0')
	{
		if (**pp_fm == '-')
			flst.is_left = 1;
		else if (**pp_fm == '0' && *(*pp_fm - 1) != '.')
			flst.is_zero = 1;
		*pp_fm += 1;
	}
	while ((**pp_fm == '-' || **pp_fm == '0' || **pp_fm == '*' || \
		**pp_fm == '.' || (**pp_fm >= '0' && **pp_fm <= '9')) && \
		pp_fm != NULL && *pp_fm != NULL)
	{
		if (**pp_fm == '.' && !(*(*pp_fm + 1) >= 0 && *(*pp_fm + 1) <= '9'))
			flst.pre = -1;
		else if (**pp_fm >= '0' && **pp_fm <= '9')
			get_flag_value(pp_fm);
		else if (**pp_fm == '*')
		{
			if (*(*pp_fm - 1) == '.')
				flst.p_wild = va_arg(ap, int);
			else
				flst.w_wild = va_arg(ap, int);
		}
		*pp_fm += 1;
	}
}

long long		get_arg(const char format, va_list ap, char **pp_arg)
{
	if (format == 'c' || format == 'd' || format == 'i' || format == 'u')
		g_ld = va_arg(ap, int);
	else if (format == 's')
		*pp_arg = va_arg(ap, char *);
	else if (format == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", pp_arg, format);
	else if (format == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", pp_arg, format);
	else if (format == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", pp_arg,
		format);
	else if (format == '%')
		g_ld = '%';
	else
		g_error = -1;
	ft_get_size(format, *pp_arg);
	return (g_ld);
}

void			print_arg(const char format, char *p_arg)
{
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		if (p_arg == NULL)
		{
			write(1, "(null)", g_arglen);
			g_count += g_arglen;
		}
		else if (format == 'p')
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(p_arg, 1);
		}
		else if ((size_t)g_arglen == ft_strlen(p_arg))
			ft_putstr_fd(p_arg, 1);
		else if ((size_t)g_arglen != ft_strlen(p_arg))
		{
			write(1, p_arg, g_arglen);
			g_count += g_arglen;
		}
	}
	else if (format == 'c' || format == '%')
		ft_putchar_fd(g_ld, 1);
	else if (format == 'd' || format == 'i' || format == 'u')
		ft_putnbr_fd(g_ld, 1);
	ft_print_flag(format);
	ft_free(format, (void **)&p_arg);
}

int				ft_printf(const char *format, ...)
{
	char		*p_arg;
	va_list		ap;

	ft_globalclear();
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			get_flag(&format, ap);
			g_ld = get_arg(*format, ap, &p_arg);
			if (g_error == -1)
				return (g_count);
			ft_print_flag(*format);
			print_arg(*format, p_arg);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (g_count);
}
