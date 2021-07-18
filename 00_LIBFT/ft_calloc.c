/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:11:14 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 18:16:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
