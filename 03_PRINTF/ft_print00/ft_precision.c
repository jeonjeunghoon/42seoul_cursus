/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:41:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 16:10:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(const char **ppf, va_list ap, const char f)
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
			len = ft_digitlen(l.p, f);
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