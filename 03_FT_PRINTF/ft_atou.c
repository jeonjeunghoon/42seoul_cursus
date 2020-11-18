/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 12:14:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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