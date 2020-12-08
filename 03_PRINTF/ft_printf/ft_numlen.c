/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:02:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:55 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				u_numlen(void)
{
	unsigned int	temp;
	size_t			len;

	if (g_lst.n == 0)
		return (1);
	temp = g_lst.n;
	len = 0;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

size_t				ft_numlen(long long num, const char f)
{
	int				temp;
	size_t			len;

	if (f == 'u')
	{
		len = u_numlen();
		return (len);
	}
	temp = num;
	len = 0;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
