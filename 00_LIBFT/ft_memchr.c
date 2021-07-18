/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:51:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 18:13:06 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (len--)
	{
		if (*dest == (unsigned char)c)
			return (dest);
		dest++;
	}
	return (0);
}
