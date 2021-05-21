/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:11:14 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/05/21 20:56:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (!(ptr = (void *)malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
