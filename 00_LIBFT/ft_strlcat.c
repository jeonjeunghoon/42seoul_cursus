/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:51:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:08:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dest_len;
	size_t result;

	if (!dest)
	{
		if (src != NULL)
			return (ft_strlen(src));
		return (0);
	}
	dest_len = ft_strlen(dest);
	result = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (dest_len >= size)
		result += size;
	else
	{
		while (src[i] && (i < size - dest_len - 1))
			dest[j++] = src[i++];
		result += dest_len;
		dest[j] = '\0';
	}
	return (result);
}
