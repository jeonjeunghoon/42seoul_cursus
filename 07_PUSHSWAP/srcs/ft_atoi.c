/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/06/28 16:47:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void					ft_isspace(const unsigned char **pp)
{
	while (**pp == ' ' || **pp == '\t' || **pp == '\r' \
	|| **pp == '\n' || **pp == '\v' || **pp == '\f')
		(*pp)++;
}

long long				isminus(const unsigned char **pp)
{
	long long			sign;

	sign = 1;
	if (**pp == '-' || **pp == '+')
	{
		if (**pp == '-')
			sign *= -1;
		(*pp)++;
	}
	return (sign);
}

long long				make_num(const unsigned char **pp, int sign)
{
	long long			tmp;
	size_t				i;

	i = 0;
	tmp = 0;
	while (**pp >= '0' && **pp <= '9')
	{
		tmp *= 10;
		tmp += **pp - '0';
		(*pp)++;
		i++;
	}
	if (i >= 20)
		tmp = sign > 0 ? -1 : 0;
	return (tmp);
}

void					ft_except(const char *str, long long num)
{
	int					i;

	i = 0;
	while (str[i])
	{
		if (i > 11)
			ft_exit("Error: ft_atoi\n");
		i++;
	}
	if (num < -2147483648 || num > 2147483647)
		ft_exit("Error: ft_atoi\n");
}

int						ft_atoi(const char *str)
{
	const unsigned char	*ptr;
	long long			sign;
	long long			num;

	sign = 1;
	ptr = (const unsigned char *)str;
	ft_isspace(&ptr);
	sign = isminus(&ptr);
	num = make_num(&ptr, sign);
	num *= sign;
	ft_except(str, num);
	return ((int)num);
}
