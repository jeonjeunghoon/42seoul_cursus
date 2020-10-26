/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/16 14:49:08 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		n_len(int n)
{
	size_t	ret;

	ret = n > 0 ? 0 : 1;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_itoa(int num)
{
	char	*ret;
	long	n;
	size_t	len;

	n = num;
	len = n_len(n);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len--] = 0;
	if (n < 0)
	{
		n *= -1;
		*ret = '-';
	}
	if (!n)
		*ret = '0';
	while (n)
	{
		ret[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
