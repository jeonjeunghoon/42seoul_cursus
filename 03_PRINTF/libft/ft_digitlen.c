/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:02:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/30 16:14:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_digitlen(long long digit)
{
	size_t	len;

	len = 0;
	while (digit)
	{
		digit /= 10;
		len++;
	}
	return (len);
}