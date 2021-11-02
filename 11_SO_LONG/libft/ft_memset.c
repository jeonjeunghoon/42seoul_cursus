/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:01:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/17 18:13:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int src, size_t len)
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
