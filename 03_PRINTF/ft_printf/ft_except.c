/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:54:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:30:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_except(const char f)
{
	int		n;

	if (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X')
		g_arglen = l.p == -1 ? 0 : g_arglen;
	if (f == 'p' && l.p == -1)
		g_arglen = 2;
	if (f == 'd' || f == 'i')
	{
		n = l.n;
		if (n < 0)
			l.is_minus = 1;
	}
	if (l.p)
		l.is_zero = 0;
	if (l.p && (g_arglen > l.p) && f == 's')
		g_arglen = l.p;
	if (l.p == -1 && f == 's')
		g_arglen = 0;
	if (l.p >= g_arglen && f == 's')
		l.p = 0;
}