/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:59:44 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 18:18:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(long long n)
{
	size_t	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char		*ptr;
	long long	n;
	size_t		len;

	n = num;
	len = get_len(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = 0;
	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
	}
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
