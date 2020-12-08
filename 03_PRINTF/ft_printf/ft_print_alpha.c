/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:30:22 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_alpha(void)
{
	if (g_lst.p == -1 && !g_lst.w)
		return ;
	if (g_lst.w > g_arglen)
	{
		g_lst.w -= g_arglen;
		if (g_lst.iszero)
			g_lst.w = ft_print_zero(g_lst.w);
		while (g_lst.w--)
			ft_putchar_fd(' ', 1);
	}
}
