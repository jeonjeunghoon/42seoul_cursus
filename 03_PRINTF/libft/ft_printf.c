/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/02 17:54:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			get_flag(const char **pp_fm, va_list ap, t_flist *flag_plst)
{
	while (++*pp_fm)
	{
		if (!((**pp_fm == '-' || **pp_fm == '0' || **pp_fm == '*' ||
		**pp_fm == '.' || (**pp_fm >= '0' && **pp_fm <= '9')) &&
		(pp_fm != NULL & *pp_fm != NULL)))
			return ;
		if (**pp_fm == '-')
			flag_plst->is_left = 1;
		else if (**pp_fm == '0')
			flag_plst->is_zero = 1;
		if (**pp_fm >= '0' && **pp_fm <= '9')
		{
			if (*(*pp_fm - 1) != '.')
				flag_plst->width = ft_atoi(*pp_fm, 'd');
			if (*(*pp_fm - 1) != '.')
				*pp_fm += ft_dlen(flag_plst->width) - 1;
			if (*(*pp_fm - 1) == '.')
				flag_plst->pre = ft_atoi(*pp_fm, 'd');
			if (*(*pp_fm - 1) == '.')
				*pp_fm += ft_dlen(flag_plst->pre) - 1;
		}
		else if (**pp_fm == '*')
		{
			if (*(*pp_fm - 1) == '.')
				flag_plst->p_wild = va_arg(ap, int);
			else
				flag_plst->w_wild = va_arg(ap, int);
			if (*(*pp_fm - 1) == '.')
				(*pp_fm)++;
		}
	}
}

long long		get_arg(const char format, va_list ap, char **pp_arg,\
				long long ld)
{
	if (format == 'c' || format == 'd' || format == 'i' || format == 'u')
		ld = va_arg(ap, int);
	else if (format == 's')
		*pp_arg = va_arg(ap, char *);
	else if (format == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", pp_arg);
	else if (format == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", pp_arg);
	else if (format == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", pp_arg);
	else if (format == '%')
		ld = '%';
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		g_arglen = ft_strlen(*pp_arg);
		if (format == 'p')
			g_arglen += 2;
	}
	else if (format == 'd' || format == 'i' || format == 'u')
		g_arglen = ft_dlen(ld);
	else if (format == 'c' || format == '%')
		g_arglen = 1;
	return (ld);
}

void			print_arg(const char format, char *p_arg, const long long ld,\
				t_flist *flag_plst)
{
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		if (!(((flag_plst->pre < g_arglen) || (flag_plst->p_wild < g_arglen)) \
		&& format == 's'))
			ft_putstr_fd(p_arg, 1);
		if (format == 'p')
			ft_putstr_fd("0x", 1);
	}
	else if (format == 'c' || format == '%')
		ft_putchar_fd(ld, 1);
	else if (format == 'd' || format == 'i' || format == 'u')
		ft_putnbr_fd(ld, 1);
	ft_print_flag(format, flag_plst, p_arg);
}

int				ft_printf(const char *format, ...)
{
	long long	ld;
	char		*p_arg;
	t_flist		*flag_plst;
	va_list		ap;

	if (!(flag_plst = (t_flist *)malloc(sizeof(t_flist))))
	{
		g_error = -1;
		ft_putstr_fd("ERROR: failed memory allocation.\n", 1);
		return (0);
	}
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			get_flag(&format, ap, flag_plst);
			ld = get_arg(*format, ap, &p_arg, ld);
			ft_print_flag(*format, flag_plst, p_arg);
			print_arg(*format, p_arg, ld, flag_plst);
			ft_free(*format, (void **)&p_arg);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	ft_free('l', (void **)&flag_plst);
	return (g_count);
}
