/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:19:43 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/30 17:50:14 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		len_of_index(unsigned long long nbr, int base_len)
{
	int		i;

	i = 0;
	while (nbr /= base_len)
		i++;
	return (i);
}

void		make_base(unsigned long long n, char *base, int last_i, char **ptr)
{
	while (last_i != 0 && n != 0)
	{
		(*ptr)[last_i--] = base[n % 16];
		n /= 16;
	}
}

void		ft_itob(unsigned long long n, char *base, char **ptr)
{
	int		base_len;
	size_t	last_i;

	base_len = 16;
	last_i = len_of_index(n, base_len);
	if (!(*ptr = (char *)malloc(sizeof(char) * (last_i + 1))))
		return ;
	(*ptr)[last_i] = '\0';
	if (n == 0)
	{
		**ptr = '0';
		return (0);
	}	
	make_base(n, base, last_i, ptr);
}
