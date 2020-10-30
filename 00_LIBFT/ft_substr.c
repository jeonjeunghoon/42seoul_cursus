/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:38:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/30 16:58:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (!ft_strlen(s) || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
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
