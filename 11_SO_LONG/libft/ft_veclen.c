/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veclen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:30:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/29 14:30:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_veclen(char **vec)
{
	size_t	size;

	if (vec == NULL)
		return (-1);
	size = 0;
	while (vec[size])
		size++;
	return (size);
}
