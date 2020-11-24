/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_csdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:04:14 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:27:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_csdiu(char fm, va_list ap, char *s)
{
	char	c;

	if (fm == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		g_count++;
	}
	else
	{
		if (fm == 's')
		{
			s = va_arg(ap, char *);
			g_count += ft_strlen(s);
			write(1, s, ft_strlen(s));
		}
		else if (fm == 'd' || fm == 'i' || fm == 'u')
		{
			s = ft_itoa(va_arg(ap, int), fm, s);
			ft_putnbr_fd(ft_atoi(s, fm), 1);
			ft_free(s);
		}
	}
}
