/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:19:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/01 12:35:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void		make_base(unsigned long long n, char *base, int last_i, char *ptr)
{
	while (last_i != 0 && n != 0)
	{
		ptr[--last_i] = base[n % 16];
		n /= 16;
	}
}

void		ft_itob(unsigned long long n, char *base, char **ptr_va)
{
	size_t	last_i;

	last_i = len_of_index(n);
	if (last_i > 8)
		last_i = 8;
	if (!(*ptr_va = (char *)malloc(sizeof(char) * (last_i + 1))))
		return ;
	(*ptr_va)[last_i] = '\0';
	if (n == 0)
	{
		**ptr_va = '0';
		return ;
	}
	make_base(n, base, last_i, *ptr_va);
}
