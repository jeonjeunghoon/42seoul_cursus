/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:29:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 17:53:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_num(void)
{
	if (l.w > g_arglen)
	{
		l.w -= g_arglen;
		if (l.is_zero && !l.is_left)
		{
			if (l.n < 0)
			{
				ft_putchar_fd('-', 1);
				l.minus = 1;
			}
			l.w = ft_print_zero(l.w);
		}
		else
		{
			while (l.w--)
				ft_putchar_fd(' ', 1);
		}
	}
	if (l.p > g_arglen)
	{
		if (l.n < 0)
		{
			ft_putchar_fd('-', 1);
			l.minus = 1;
			g_arglen--;
		}
		ft_print_zero(l.p - g_arglen);
	}
}