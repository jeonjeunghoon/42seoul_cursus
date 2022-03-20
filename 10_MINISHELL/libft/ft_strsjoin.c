/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:18:02 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/14 17:24:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsjoin(char **strs1, char **strs2)
{
	char	**new_strs;
	size_t	len;
	size_t	i;
	size_t	j;

	if (strs1 == NULL || strs2 == NULL)
		return (NULL);
	len = ft_two_dimension_size(strs1) + ft_two_dimension_size(strs2);
	new_strs = (char **)malloc(sizeof(char *) * (len + 1));
	new_strs[len] = NULL;
	i = 0;
	while (i < ft_two_dimension_size(strs1) && strs1[i] != NULL)
	{
		new_strs[i] = ft_strdup(strs1[i]);
		i++;
	}
	j = 0;
	while (i < len && strs2[j] != NULL)
	{
		new_strs[i] = ft_strdup(strs2[j]);
		i++;
		j++;
	}
	return (new_strs);
}
