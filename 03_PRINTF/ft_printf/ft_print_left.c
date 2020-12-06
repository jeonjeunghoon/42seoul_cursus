/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:32:08 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 19:11:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_left(const char f)
{
	int		n;

	if (f == 'i' || f == 'd')
	{
		n = l.n;
		if (n < 0 && l.p != -1)
		{
			ft_putchar_fd('-', 1);
			l.minus = 1;
			g_arglen--;
		}
	}
	if (l.p == -1 && l.n == 0)
		g_arglen = 0;
	l.p = l.p > g_arglen ? l.p - g_arglen : 0;
	ft_print_zero(l.p);
	l.w = l.w - l.p - l.is_minus > 0 ? l.w - l.p - l.is_minus : 0;
	l.p = 0;
}
