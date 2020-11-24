/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:57:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:25:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnbr_fd(long long n, int fd)
{
	char		c;
	long long	num;

	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		g_count++;
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	if (num < 10)
	{
		c = num + '0';
		write(fd, &c, 1);
		g_count++;
	}
}
