/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:32:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_left(const char f)
{
	int		n;

	if (f == 'i' || f == 'd')
	{
		n = g_lst.n;
		if (n < 0 && g_lst.p != -1)
		{
			ft_putchar_fd('-', 1);
			g_lst.minus = 1;
			g_arglen--;
		}
	}
	if ((g_lst.p == -1 && g_lst.n == 0) && (f != 'x' && f != 'X' && f != 'p'))
		g_arglen = 0;
	g_lst.p = g_lst.p > g_arglen ? g_lst.p - g_arglen : 0;
	ft_print_zero(g_lst.p);
	g_lst.w = g_lst.w - g_lst.p - g_lst.isminus > 0 ? g_lst.w - g_lst.p - g_lst.isminus : 0;
	g_lst.p = 0;
}
