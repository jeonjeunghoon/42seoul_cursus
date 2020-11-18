/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 13:57:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int num)
{
	char			*ret;
	long long		n;
	size_t			len;

	n = num;
	len = ft_toa_len;
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
