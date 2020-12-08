/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printflag(const char f)
{
	if (!(g_lst.isleft))
	{
		if (f == 'c' || f == 's' || f == '%')
			ft_print_alpha();
		else if (f == 'd' || f == 'i' || f == 'u' \
		|| f == 'x' || f == 'X' || f == 'p')
			ft_print_num(f);
		g_lst.isleft = 1;
	}
}
