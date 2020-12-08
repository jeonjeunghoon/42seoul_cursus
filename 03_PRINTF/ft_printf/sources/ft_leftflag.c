/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:54:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_leftflag(const char f)
{
	ft_except(f);
	if (g_lst.isleft)
	{
		if (f == 'd' || f == 'i' || f == 'u' || \
		f == 'x' || f == 'X' || f == 'p')
			ft_print_left(f);
		g_lst.isleft = 0;
	}
	else
		ft_printflag(f);
}
