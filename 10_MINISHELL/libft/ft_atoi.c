/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	atoi_isspace(const unsigned char **pp)
{
	while (**pp == ' ' || **pp == '\t' || **pp == '\r' \
	|| **pp == '\n' || **pp == '\v' || **pp == '\f')
		(*pp)++;
}

int	isminus(const unsigned char **pp)
{
	int	sign;

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

int	ft_atoi(const char *str)
{
	const unsigned char	*ptr;
	int					sign;
	long long			num;

	sign = 1;
	ptr = (const unsigned char *)str;
	atoi_isspace(&ptr);
	sign = isminus(&ptr);
	num = make_num(&ptr, sign);
	return ((int)(num * sign));
}
