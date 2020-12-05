/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:09:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/16 18:53:22 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))) || !s1)
		return (0);
	ptr[len] = 0;
	i = 0;
	while (len)
	{
		*(ptr + i++) = *s1++;
		len--;
	}
	return (ptr);
}
