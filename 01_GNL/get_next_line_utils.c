/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:06:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/10/30 21:37:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (((unsigned char *)s)[res])
		res++;
	return (res);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ptr[len] = 0;
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	res[ft_strlen(s1) + ft_strlen(s2)] = 0;
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}
