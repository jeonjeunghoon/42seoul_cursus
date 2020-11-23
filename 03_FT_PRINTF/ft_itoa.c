/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/23 19:13:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_toa_len(unsigned int n, char fm)
{
	unsigned int	ret;

	if (fm == 'd' || fm == 'i')
		ret = n > 0 ? 0 : 1;
	else
		ret = 0;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char				*ft_utoa(unsigned int num, char fm)
{
	char			*ret;
	unsigned int	n;
	size_t			len;

	n = num;
	len = ft_toa_len(n, fm);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len--] = 0;
	if (!n)
		*ret = '0';
	while (n)
	{
		ret[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}

char		*ft_itoa(int num, char fm)
{
	char			*ret;
	long long		n;
	size_t			len;

	if (fm == 'u' || fm == 'p' || fm == 'x' || fm == 'X')
		ret = ft_utoa(num, fm);
	else
	{
		n = num;
		len = ft_toa_len(n, fm);
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
	}
	return (ret);
}
