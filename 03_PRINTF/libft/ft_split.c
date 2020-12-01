/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:53:55 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/01 11:28:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		col_size(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i])
		{
			ret++;
			while ((s[i] == c) && s[i])
				i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	if ((s[i - 1] != c) || s[i])
		ret++;
	return (ret);
}

size_t		row_size(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		ret++;
	}
	return (ret);
}

void		ft_free(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		ret[i++] = NULL;
	}
}

char		**make_split(char const *s, char **ret, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		j = 0;
		if (*s != c && *s)
		{
			if (!(ret[i] = (char *)malloc(sizeof(char) * (row_size(s, c) + 1))))
			{
				ft_free(ret);
				return (0);
			}
			while ((*s != c) && *s)
				ret[i][j++] = *s++;
			ret[i++][j] = 0;
		}
		if (*s == c && *s)
			s++;
	}
	ret[i] = 0;
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	if (!(ret = (char **)malloc(sizeof(char *) * (col_size(s, c) + 1))))
		return (0);
	ret = make_split(s, ret, c);
	return (ret);
}
