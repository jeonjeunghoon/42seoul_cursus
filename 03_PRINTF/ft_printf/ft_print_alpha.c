/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:30:22 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 17:45:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_alpha(void)
{
	if (l.p == -1 && !l.w)
		return ;
	if (l.w > g_arglen)
	{
		l.w -= g_arglen;
		if (l.is_zero)
			l.w = ft_print_zero(l.w);
		while (l.w--)
			ft_putchar_fd(' ', 1);
	}
}