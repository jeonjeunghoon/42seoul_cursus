/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:34:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:53:22 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_width(const char **ppf, va_list ap, const char f)
{
	size_t	len;

	len = 0;
	if (**ppf >= '0' && **ppf <= '9')
	{
		g_lst.w = ft_atoi(*ppf, 'u');
		len = ft_numlen(g_lst.w, f);
		*ppf += len;
	}
	else if (**ppf == '*')
	{
		g_lst.w = va_arg(ap, int);
		*ppf += 1;
	}
}
