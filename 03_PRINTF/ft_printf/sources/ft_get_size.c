/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:30:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		n = g_lst.n;
	if (f == 'd' || f == 'i' || f == 'u')
	{
		g_arglen = ft_numlen(g_lst.n, f);
		if (g_lst.n <= 0 && f != 'u')
			g_arglen++;
	}
	else if (f == 'c' || f == '%')
		g_arglen = 1;
}
