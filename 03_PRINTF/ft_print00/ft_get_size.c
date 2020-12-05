/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:30:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 16:32:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_size(const char f, char *p)
{
	if (f == 's' || f == 'x' || f == 'X' || f == 'p')
	{
		if (p == NULL)
			g_arglen = 6;
		else
		{
			g_arglen = ft_strlen(p);
			if (f == 'p')
				g_arglen += 2;
		}
	}
	else if (f == 'd' || f == 'i' || f == 'u')
	{
		if (f == 'u')
			g_arglen = ft_digitlen(l.un);
		else if (f == 'd' || f == 'i')
			g_arglen = ft_digitlen(l.n);
		if (l.n == 0 || l.un == 0)
			g_arglen = 1;
	}
	else if (f == 'c' || f == '%')
		g_arglen = 1;
}
