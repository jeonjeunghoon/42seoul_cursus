/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:56:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 15:45:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_structclear(void)
{
	flag_lst.is_left = 0;
	flag_lst.is_zero = 0;
	flag_lst.pre = 0;
	flag_lst.p_wild = 0;
	flag_lst.width = 0;
	flag_lst.w_wild = 0;
}
