/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:54:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:06:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_leftflag(const char f)
{
	ft_except(f);
	if (l.is_left)
	{
		if (f == 'd' || f == 'i' || f == 'u' || \
		f == 'x' || f == 'X' || f == 'p')
			ft_print_left(f);
		l.is_left = 0;
	}
	else
	{
		ft_printflag(f);
	}
}
