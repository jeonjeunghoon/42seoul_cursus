/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:04:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printflag(const char f)
{
	if (!(l.is_left))
	{
		if (f == 'c' || f == 's' || f == '%')
			ft_print_alpha();
		else if (f == 'd' || f == 'i' || f == 'u' \
		|| f == 'x' || f == 'X' || f == 'p')
			ft_print_num(f);
		l.is_left = 1;
	}
}
