/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:38:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:17:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char *s, int begin, int end)
{
	char		*ptr;
	int			len;
	int			i;

	len = end - begin;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[begin + i])
	{
		ptr[i] = s[begin + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
