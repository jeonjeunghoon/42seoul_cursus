/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:54:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 17:25:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_except(const char f)
{
	if (l.n < 0)
		l.is_minus = 1;
	if (l.p)
		l.is_zero = 0;
	if (l.p && (g_arglen > l.p) && f == 's')
		g_arglen = l.p;
	if (l.p == -1 && f == 's')
		g_arglen = 0;
}