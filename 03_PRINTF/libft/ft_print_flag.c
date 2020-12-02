/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/02 17:53:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		is_alpha(const char format, t_flist *flag_plst, char *p_arg)
{
	size_t	i;

	i = 0;
	if ((flag_plst->width > g_arglen) || (flag_plst->w_wild > g_arglen))
	{
		i = flag_plst->width > flag_plst->w_wild ? \
		flag_plst->width : flag_plst->w_wild;
		i -= g_arglen;
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		is_num(const char format, t_flist *flag_plst, char *p_arg)
{
	size_t	i;

	i = 0;
	if ((flag_plst->pre > g_arglen) || (flag_plst->p_wild > g_arglen))
	{
		i = flag_plst->pre > flag_plst->p_wild ? \
		flag_plst->pre : flag_plst->p_wild;
		i -= g_arglen;
		while (i--)
			ft_putchar_fd('0', 1);
	}
	else if ((flag_plst->width > g_arglen) || (flag_plst->w_wild > g_arglen))
	{
		i = flag_plst->width > flag_plst->w_wild ? \
		flag_plst->width : flag_plst->w_wild;
		i -= g_arglen;
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		ft_print_flag(const char format, t_flist *flag_plst, char *p_arg)
{
	if (flag_plst->is_left == 1)
		flag_plst->is_left = 0;
	else if (flag_plst->is_left == 0)
	{
		if (format == 'd' || format == 'i' || format == 'u' || format == 'x' \
		|| format == 'X' || format == 'p')
			is_num(format, flag_plst, p_arg);
		else if (format == 'c' || format == 's' || format == '%')
			is_alpha(format, flag_plst, p_arg);
		ft_structclear(flag_plst);
	}
	if (((flag_plst->pre < g_arglen) || (flag_plst->p_wild < g_arglen)) && \
	format == 's')
	{
		g_arglen = flag_plst->pre > flag_plst->p_wild ? \
		flag_plst->pre : flag_plst->p_wild;
		write(1, p_arg, g_arglen);
		g_count += g_arglen;
		flag_plst->p_wild = 0;
		flag_plst->pre = 0;
	}
}
