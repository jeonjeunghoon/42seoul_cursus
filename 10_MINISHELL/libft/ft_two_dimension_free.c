/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_dimension_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:28:17 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 00:18:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_two_dimension_free(char ***strs)
{
	int	i;

	i = 0;
	if (*strs == NULL)
		return ;
	while ((*strs)[i] != NULL)
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
		i++;
	}
	free(*strs);
	*strs = NULL;
}
