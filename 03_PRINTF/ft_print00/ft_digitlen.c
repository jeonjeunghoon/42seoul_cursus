/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:02:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 15:38:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				u_digitlen(unsigned int u_n)
{
	unsigned int	digit;
	size_t			len;

	digit = u_n;
	len = 0;
	while (digit)
	{
		digit /= 10;
		len++;
	}
	return (len);
}

size_t			ft_digitlen(long long digit, const char f)
{
	size_t		len;
	int			n;

	if (f == 'u')
		u_digitlen(digit);
	len = 0;
	n = digit;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
