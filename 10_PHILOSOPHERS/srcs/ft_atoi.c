/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:48:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/16 20:22:48 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_isspace(const unsigned char **pp)
{
	while (**pp == ' ' || **pp == '\t' || **pp == '\r' \
	|| **pp == '\n' || **pp == '\v' || **pp == '\f')
		(*pp)++;
}

long long	isminus(const unsigned char **pp)
{
	long long	sign;

	sign = 1;
	if (**pp == '-' || **pp == '+')
	{
		if (**pp == '-')
			sign *= -1;
		(*pp)++;
	}
	return (sign);
}

long long	make_num(const unsigned char **pp, int sign)
{
	long long	tmp;
	size_t		i;

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
	{
		if (sign > 0)
			tmp = -1;
		else
			tmp = 0;
	}
	return (tmp);
}

void	ft_except(const char *str, long long num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 11)
			exit(1);
		i++;
	}
}

long long	ft_atoi(const char *str)
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
	return (num);
}
