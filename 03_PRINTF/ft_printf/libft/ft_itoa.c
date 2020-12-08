/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:29:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_toa_len(long long n, char f)
{
	unsigned int	res;

	if (f == 'd' || f == 'i')
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

char				*ft_utoa(unsigned int n, char f, char *s)
{
	size_t			len;

	len = ft_toa_len(n, f);
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

char				*ft_itoa(long long n, const char f, char *s)
{
	size_t			len;

	if (f == 'u' || f == 'p' || f == 'x' || f == 'X')
		s = ft_utoa(n, f, s);
	else
	{
		len = ft_toa_len(n, f);
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
