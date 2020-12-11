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

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		i = 0;
		while (len-- && s[start])
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
