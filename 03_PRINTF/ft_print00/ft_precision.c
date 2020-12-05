/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:41:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 17:23:11 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(const char **ppf, va_list ap)
{
	size_t	len;

	len = 0;
	if (**ppf == '.')
	{
		*ppf += 1;
		while (**ppf == '0')
			*ppf += 1;
		if ((**ppf >= '1' && **ppf <= '9'))
		{
			l.p = ft_atoi(*ppf, 'd');
			len = ft_digitlen(l.p);
			*ppf += len;
		}
		else if (**ppf == '*')
		{
			l.p = va_arg(ap, int);
			*ppf += 1;
		}
		else
			l.p = -1;
	}
}