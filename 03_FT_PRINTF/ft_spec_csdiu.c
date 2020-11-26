/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_csdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:04:14 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/26 23:16:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_csdiu(char fm, va_list ap, char *s)
{
	char	c;

	if (fm == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else
	{
		if (fm == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
		}
		else if (fm == 'd' || fm == 'i' || fm == 'u')
		{
			s = ft_itoa(va_arg(ap, int), fm, s);
			ft_putnbr(ft_atoi(s, fm), fm);
			ft_free((void **)&s);
		}
	}
}
