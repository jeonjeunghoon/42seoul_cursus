/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:50:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 13:55:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_toa_len(unsigned int n)
{
	unsigned int	ret;

	ret = n > 0 ? 0 : 1;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
} 