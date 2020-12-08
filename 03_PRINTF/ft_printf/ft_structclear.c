/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:56:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:42:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_structclear(void)
{
	g_lst.isleft = 0;
	g_lst.iszero = 0;
	g_lst.isminus = 0;
	g_lst.minus = 0;
	g_lst.p = 0;
	g_lst.w = 0;
	g_lst.n = 0;
}
