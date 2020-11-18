/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:01:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 12:12:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi(const char *str)
{
	long long		res;
	long long		sign;
	long long		i;

	res = 0;
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
