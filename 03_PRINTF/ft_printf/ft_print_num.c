/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:29:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:28:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_num(const char f)
{
	int		n;

	if (f == 'd' || f == 'i')
		n = l.n;
	if (l.is_zero)
	{
		l.w -= g_arglen;
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			l.minus = 1;
			g_arglen--;
		}
		l.w = ft_print_zero(l.w);
	}
	else if (l.w > g_arglen)
	{
		if (l.w > g_arglen + l.p && l.is_minus && l.p)
			l.w -= 1;
		l.w -= g_arglen > l.p ? g_arglen : l.p;
		while (l.w--)
			ft_putchar_fd(' ', 1);
	}
	if (l.p > g_arglen)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			l.minus = 1;
			g_arglen--;
		}
		ft_print_zero(l.p - g_arglen);
	}
}
