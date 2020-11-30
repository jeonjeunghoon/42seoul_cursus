/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:36:53 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/14 13:24:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s != (unsigned char)c)
			*(unsigned char *)d = *(unsigned char *)s;
		else
		{
			*(unsigned char *)d = *(unsigned char *)s;
			d++;
			return (d);
		}
		d++;
		s++;
	}
	return (0);
}
