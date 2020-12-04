/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:30:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 17:11:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_size(const char format, char *p_arg)
{
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		if (p_arg == NULL)
			g_arglen = 6;
		else
		{
			g_arglen = ft_strlen(p_arg);
			if (format == 'p')
				g_arglen += 2;
		}
	}
	else if (format == 'd' || format == 'i' || format == 'u')
	{
		g_arglen = ft_dlen(g_ld);
		if (g_ld == 0)
			g_arglen = 1;
	}
	else if (format == 'c' || format == '%')
		g_arglen = 1;
}
