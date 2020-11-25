/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_pxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:26:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/25 16:53:23 by jeunjeon         ###   ########.fr       */
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
		ft_putstr("0x");
		ft_putnbr_base(p, "0123456789abcdef", fm);
	}
	if (fm == '%')
		ft_putchar('%');
}
