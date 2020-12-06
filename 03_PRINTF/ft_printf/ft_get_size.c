/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:30:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 21:29:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_size(const char f, char *p)
{
	int	n;

	if (f == 's' || f == 'x' || f == 'X' || f == 'p')
	{
		if (p == NULL)
			g_arglen = 6;
		else
			g_arglen = ft_strlen(p);
		if (f == 'p')
			g_arglen += 2;
	}
	if (f == 'd' || f == 'i')
		n = l.n;
	if (f == 'd' || f == 'i' || f == 'u')
	{
		g_arglen = ft_digitlen(l.n, f);
		if (n <= 0 || l.n <= 0)
			g_arglen++;
	}
	else if (f == 'c' || f == '%')
		g_arglen = 1;
}
