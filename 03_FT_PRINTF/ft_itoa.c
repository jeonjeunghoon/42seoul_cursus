/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:42:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_toa_len(long long n, char fm)
{
	unsigned int	res;

	if (fm == 'd' || fm == 'i')
		res = n > 0 ? 0 : 1;
	else
		res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char				*ft_utoa(unsigned int n, char fm, char *s)
{
	size_t			len;

	len = ft_toa_len(n, fm);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len--] = 0;
	if (!n)
		*s = '0';
	while (n)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char				*ft_itoa(long long n, char fm, char *s)
{
	size_t			len;

	if (fm == 'u' || fm == 'p' || fm == 'x' || fm == 'X')
		s = ft_utoa(n, fm, s);
	else
	{
		len = ft_toa_len(n, fm);
		if (!(s = malloc(sizeof(char) * (len + 1))))
			return (0);
		s[len--] = 0;
		if (n < 0)
		{
			n *= -1;
			*s = '-';
		}
		if (!n)
			*s = '0';
		while (n)
		{
			s[len--] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (s);
}
