/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:54:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:44:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		except_alpha(const char f)
{
	if (g_lst.n == '%' || f == 'c')
		g_lst.p = 0;
	if (f == 's' && g_lst.p >= g_arglen)
		g_lst.p = 0;
	if (f == 's' && g_lst.p > 0 && (g_arglen > g_lst.p))
		g_arglen = g_lst.p;
	if (f == 's' && g_lst.p == -1)
		g_arglen = 0;
}

void		except_number(const char f)
{
	if ((f == 'd' || f == 'i' || f == 'u') && g_lst.p == -1 && g_lst.n == 0)
		g_arglen = 0;
	if ((f == 'd' || f == 'i' || f == 'u') && g_lst.p == -1 && g_lst.n != 0)
		g_lst.p = 0;
	if ((f == 'd' || f == 'i') && g_lst.n < 0)
		g_lst.isminus = 1;
	if ((f == 'x' || f == 'X') && g_lst.n == -1 && g_lst.p == -1)
		g_arglen = 0;
	if (f == 'p' && g_lst.p == -1 && g_lst.n == -1)
		g_arglen = 2;
}

void		ft_except(const char f)
{
	if (g_lst.w < 0)
	{
		g_lst.w *= -1;
		g_lst.isleft = 1;
		g_lst.iszero = 0;
	}
	if ((g_lst.p == -1 || g_lst.p > 0) && f != '%' && f != 'c')
		g_lst.iszero = 0;
	except_alpha(f);
	except_number(f);
}
