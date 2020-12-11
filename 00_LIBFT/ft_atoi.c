/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 17:17:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_isspace(const unsigned char **pp)
{
	while (**pp == ' ' || **pp == '\t' || **pp == '\r' \
	|| **pp == '\n' || **pp == '\v' || **pp == '\f')
		(*pp)++;
}

int						isminus(const unsigned char **pp)
{
	int					sign;

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

int						ft_atoi(const char *str)
{
	const unsigned char	*ptr;
	int					sign;
	long long			num;

	sign = 1;
	ptr = (const unsigned char *)str;
	ft_isspace(&ptr);
	sign = isminus(&ptr);
	num = make_num(&ptr, sign);
	return ((int)(num * sign));
}
