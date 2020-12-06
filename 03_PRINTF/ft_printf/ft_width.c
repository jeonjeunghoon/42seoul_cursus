/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:34:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:02:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_width(const char **ppf, va_list ap, const char f)
{
	size_t	len;

	len = 0;
	if (**ppf >= '0' && **ppf <= '9')
	{
		l.w = ft_atoi(*ppf, 'u');
		len = ft_digitlen(l.w, f);
		*ppf += len;
	}
	else if (**ppf == '*')
	{
		l.w = va_arg(ap, int);
		*ppf += 1;
	}
}