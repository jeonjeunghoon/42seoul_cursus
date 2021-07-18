/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:04:09 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 17:54:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	size_t	i;

	i = -1;
	if (!d && !s)
		return (0);
	while (++i < n)
		*(unsigned char *)(d + i) = *(unsigned char *)(s + i);
	return (d);
}
