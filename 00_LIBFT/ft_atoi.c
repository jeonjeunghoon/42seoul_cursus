/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/21 11:32:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace(const char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' ||
	*str == '\v' || *str == '\f')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long	res;
	long	sign;
	long	i;

	res = 0;
	sign = 1;
	while (ft_isspace(str))
		str++;
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
