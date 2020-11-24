/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_pxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:26:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:44:30 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_spec_pxp(char fm, va_list ap, char *s)
{
	unsigned long long p;

	if (fm == 'x' || fm == 'X')
	{
		s = ft_itoa(va_arg(ap, int), fm, s);
		ft_putnbr_base(ft_atoi(s, fm), "0123456789abcdef", fm);
		ft_free(s);
	}
	if (fm == 'p')
	{
		p = va_arg(ap, unsigned long long);
		write(1, "0x", 2);
		g_count += 2;
		ft_putnbr_base(p, "0123456789abcdef", fm);
	}
}
