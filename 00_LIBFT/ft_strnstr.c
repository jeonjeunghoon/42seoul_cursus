/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:56:50 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 17:47:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_n_in_h(const char *h, const char *n, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if ((h[i] != n[j]) || !h[i] || !len)
			return (0);
		i++;
		j++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	i = 0;
	if (!*n)
		return ((char *)h);
	else
	{
		while (len && h[i])
		{
			if (is_n_in_h(h, n, i, len))
				return ((char *)&(h[i]));
			i++;
			len--;
		}
	}
	return (0);
}
