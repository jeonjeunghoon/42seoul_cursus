/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_dimension_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:30:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_two_dimension_size(char **strs)
{
	size_t	size;

	if (strs == NULL)
		return (-1);
	size = 0;
	while (strs[size] != NULL)
		size++;
	return (size);
}
