/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:01:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:22:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *dest, int src, size_t len)
{
	unsigned char	*head;

	head = (unsigned char *)dest;
	while (len--)
	{
		*head = (unsigned char)src;
		head++;
	}
	return (dest);
}
