/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:46:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/14 17:10:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char **strs)
{
	char	**new_strs;
	size_t	len;
	size_t	i;

	if (strs == NULL)
		return (NULL);
	len = ft_two_dimension_size(strs);
	new_strs = (char **)malloc(sizeof(char *) * (len + 1));
	new_strs[len] = NULL;
	i = 0;
	while (i < len && strs[i])
	{
		new_strs[i] = ft_strdup(strs[i]);
		i++;
	}
	return (new_strs);
}
