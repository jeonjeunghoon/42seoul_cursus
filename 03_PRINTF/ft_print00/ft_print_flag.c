/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 17:44:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_flag(const char f)
{
	ft_except(f);
	if (l.is_left)
	{
		if ((l.p || l.w) && (f != 'c' || f != '%'))
			ft_print_left(f);
		l.is_left = 0;
	}
	else if (!(l.is_left))
	{
		if (f == 'c' || f == 's' || f == '%')
			ft_print_alpha();
		else if (f == 'd' || f == 'i' || f == 'u' \
		|| f == 'x' || f == 'X' || f == 'p')
			ft_print_num();
	}
}
