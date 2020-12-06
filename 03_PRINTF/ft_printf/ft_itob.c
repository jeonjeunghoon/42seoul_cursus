/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:19:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 16:31:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		make_base(unsigned long long n, char *base, int last_i, char *p_arg)
{
	while (last_i != 0 && n != 0)
	{
		p_arg[--last_i] = base[n % 16];
		n /= 16;
	}
}

void		ft_itob(unsigned long long n, char *base, char **pp_arg, \
			char format)
{
	size_t	last_i;

	last_i = len_of_index(n);
	if ((last_i > 8) && (format == 'x' || format == 'X'))
		last_i = 8;
	if (!(*pp_arg = (char *)malloc(sizeof(char) * (last_i + 1))))
		return ;
	(*pp_arg)[last_i] = '\0';
	if (n == 0)
	{
		**pp_arg = '0';
		return ;
	}
	make_base(n, base, last_i, *pp_arg);
}
