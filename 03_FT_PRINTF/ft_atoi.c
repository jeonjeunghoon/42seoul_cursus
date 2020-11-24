/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:01:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:05:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_atou(char *s)
{
	unsigned int	res;
	unsigned int	temp;
	unsigned int	i;

	res = 0;
	temp = 0;
	i = 0;
	if (*(unsigned char *)s == '-' || *(unsigned char *)s == '+')
	{
		if (*(unsigned char *)s == '-')
			res = 4294967295;
		s++;
	}
	while (*(unsigned char *)s >= '0' && *(unsigned char *)s <= '9')
	{
		temp *= 10;
		temp += *(unsigned char *)s - '0';
		s++;
		i++;
	}
	if (res)
		res -= (temp - 1);
	else
		res = temp;
	return (res);
}

long long			ft_atoi(char *s, char fm)
{
	long long		res;
	long long		sign;
	long long		i;

	res = 0;
	if (fm == 'u' || fm == 'p' || fm == 'x' || fm == 'X')
		return (ft_atou(s));
	sign = 1;
	if (*(unsigned char *)s == '-' || *(unsigned char *)s == '+')
	{
		if (*(unsigned char *)s == '-')
			sign *= -1;
		s++;
	}
	i = 0;
	while (*(unsigned char *)s >= '0' && *(unsigned char *)s <= '9')
	{
		res *= 10;
		res += *(unsigned char *)s - '0';
		s++;
		i++;
	}
	if (i >= 20)
		res = sign > 0 ? -1 : 0;
	return ((int)(res * sign));
}
