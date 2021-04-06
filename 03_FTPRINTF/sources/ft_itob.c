/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:19:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		len_of_index(unsigned long long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void		make_base(unsigned long long n, char *p_base, int last_i, char *p)
{
	while (last_i != 0 && n != 0)
	{
		p[--last_i] = p_base[n % 16];
		n /= 16;
	}
}

void		ft_itob(unsigned long long n, char *p_base, char **pp, \
			char f)
{
	size_t	last_i;

	if (n == 0)
		g_lst.n = -1;
	last_i = len_of_index(n);
	if ((last_i > 8) && (f == 'x' || f == 'X'))
		last_i = 8;
	if (!(*pp = (char *)malloc(sizeof(char) * (last_i + 1))))
		return ;
	(*pp)[last_i] = '\0';
	if (n == 0)
	{
		**pp = '0';
		return ;
	}
	make_base(n, p_base, last_i, *pp);
}
