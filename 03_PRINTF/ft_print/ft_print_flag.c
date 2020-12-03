/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 15:51:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_exception(char *p_arg)
{
	int		precision;

	precision = flag_lst.pre > flag_lst.p_wild ? \
	flag_lst.pre : flag_lst.p_wild;
	if (g_arglen > precision)
	{
		g_arglen = precision;
		write(1, p_arg, g_arglen);
		g_count += g_arglen;
		flag_lst.p_wild = 0;
		flag_lst.pre = 0;
	}
}

size_t		print_zero(size_t i)
{
	while (i)
	{
		ft_putchar_fd('0', 1);
		i--;
	}
	return (i);
}

void		is_alpha(void)
{
	size_t	i;

	i = 0;
	if ((flag_lst.width > g_arglen) || (flag_lst.w_wild > g_arglen))
	{
		i = flag_lst.width > flag_lst.w_wild ? \
		flag_lst.width : flag_lst.w_wild;
		i -= g_arglen;
		if (flag_lst.is_zero)
			i = print_zero(i);
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		is_num(void)
{
	size_t	i;

	i = 0;
	if ((flag_lst.pre > g_arglen) || (flag_lst.p_wild > g_arglen))
	{
		i = flag_lst.pre > flag_lst.p_wild ? \
		flag_lst.pre : flag_lst.p_wild;
		i -= g_arglen;
		while (i--)
			ft_putchar_fd('0', 1);
	}
	else if ((flag_lst.width > g_arglen) || (flag_lst.w_wild > g_arglen))
	{
		i = flag_lst.width > flag_lst.w_wild ? \
		flag_lst.width : flag_lst.w_wild;
		i -= g_arglen;
		if (flag_lst.is_zero)
			i = print_zero(i);
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		ft_print_flag(const char format, char *p_arg)
{
	if (flag_lst.is_left)
	{
		if (((flag_lst.pre) || (flag_lst.p_wild)) && (format == 's'))
			ft_exception(p_arg);
		flag_lst.is_left = 0;
	}
	else if (!(flag_lst.is_left))
	{
		if (((flag_lst.pre) || (flag_lst.p_wild)) && format == 's')
			ft_exception(p_arg);
		if (format == 'c' || format == 's' || format == '%')
			is_alpha();
		else if (format == 'd' || format == 'i' || format == 'u' || \
		format == 'x' || format == 'X' || format == 'p')
			is_num();
		ft_structclear();
	}
}
