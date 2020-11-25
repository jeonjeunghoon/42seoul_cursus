/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:45:53 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/25 17:39:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr(long long num)
{
	if (num > 0 && g_flag)
	{
		ft_putchar(' ');
		g_flag = 0;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		g_flag = 0;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num %= 10;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
	}
}
