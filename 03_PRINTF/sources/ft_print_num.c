/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:29:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_iszero(const char f, int n)
{
	g_lst.w -= g_arglen;
	if (n < 0 && f != 'u' && f != 'x' && f != 'X')
	{
		ft_putchar_fd('-', 1);
		g_lst.minus = 1;
		g_arglen--;
	}
	g_lst.w = ft_print_zero(g_lst.w);
}

void		print_width(void)
{
	if (g_lst.p > 0 && g_lst.isminus)
	{
		if (g_lst.p > g_arglen - 1)
			g_lst.w -= 1;
	}
	g_lst.w -= g_arglen > g_lst.p ? g_arglen : g_lst.p;
	while (g_lst.w > 0)
	{
		ft_putchar_fd(' ', 1);
		g_lst.w -= 1;
	}
}

void		print_precision(const char f, int n)
{
	if (n < 0 && f != 'u' && f != 'x' && f != 'X')
	{
		ft_putchar_fd('-', 1);
		g_lst.minus = 1;
	}
	ft_print_zero(g_lst.p - (g_arglen - g_lst.isminus));
}

void		ft_print_num(const char f)
{
	int		n;

	if (f == 'd' || f == 'i')
		n = g_lst.n;
	if (g_lst.iszero)
		print_iszero(f, n);
	else if (g_lst.w > g_arglen)
		print_width();
	if (g_lst.p > g_arglen - g_lst.isminus)
		print_precision(f, n);
}
