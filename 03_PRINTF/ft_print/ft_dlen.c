/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:02:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 16:12:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_dlen(long long digit)
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
