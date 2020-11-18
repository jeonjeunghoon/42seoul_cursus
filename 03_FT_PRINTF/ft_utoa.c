/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:47:51 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 13:57:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_utoa(unsigned int num)
{
	char			*ret;
	unsigned int	n;
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
