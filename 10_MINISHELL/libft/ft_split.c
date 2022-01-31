/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:53:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 01:14:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	col_size(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			len++;
			while ((s[i] == c) && s[i])
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		len++;
	return (len);
}

size_t	row_size(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**make_split(char const *s, char **pp, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		j = 0;
		if (*s != c)
		{
			pp[i] = (char *)malloc(sizeof(char) * (row_size(s, c) + 1));
			if (pp[i] == NULL)
			{
				ft_two_dimension_free(&pp);
				return (NULL);
			}
			while ((*s != c) && *s)
				pp[i][j++] = *s++;
			pp[i++][j] = 0;
		}
		if (*s)
			s++;
	}
	pp[i] = 0;
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	char	**pp;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	len = col_size(s, c);
	pp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!pp)
		return (NULL);
	pp = make_split(s, pp, c);
	return (pp);
}
