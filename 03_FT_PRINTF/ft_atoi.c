/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:01:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/23 19:14:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_atou(char *str)
{
	unsigned int	res;
	unsigned int	temp;
	unsigned int	i;

	res = 0;
	temp = 0;
	i = 0;
	if (*(unsigned char *)str == '-' || *(unsigned char *)str == '+')
	{
		if (*(unsigned char *)str == '-')
			res = 4294967295;
		str++;
	}
	while (*(unsigned char *)str >= '0' && *(unsigned char *)str <= '9')
	{
		temp *= 10;
		temp += *(unsigned char *)str - '0';
		str++;
		i++;
	}
	if (res)
	{
		res -= (temp - 1);
		return (res);
	}
	else
	{
		res = temp;
		return (res);
	}
	return (0);
}

long long			ft_atoi(char *str, char fm)
{
	long long		res;
	long long		sign;
	long long		i;

	res = 0;
	if (fm == 'u' || fm == 'p' || fm == 'x' || fm == 'X')
		return (ft_atou(str));
	sign = 1;
	if (*(unsigned char *)str == '-' || *(unsigned char *)str == '+')
	{
		if (*(unsigned char *)str == '-')
			sign *= -1;
		str++;
	}
	i = 0;
	while (*(unsigned char *)str >= '0' && *(unsigned char *)str <= '9')
	{
		res *= 10;
		res += *(unsigned char *)str - '0';
		str++;
		i++;
	}
	if (i >= 20)
		res = sign > 0 ? -1 : 0;
	return ((int)(res * sign));
}
