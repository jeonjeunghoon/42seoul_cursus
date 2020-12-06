/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:14:28 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 15:12:30 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				un_putnbr(unsigned int u_n, int fd, const char f)
{
	unsigned int	u_num;

	u_num = u_n;
	if (u_num >= 10)
	{
		un_putnbr(u_num / 10, fd, f);
		u_num %= 10;
	}
	if (u_num < 10)
		ft_putchar_fd(u_num + '0', 1);
}

void				ft_putnbr_fd(long long n, int fd, const char f, int minus)
{
	int				num;

	if (f == 'u')
	{
		un_putnbr(n, fd, f);
		return ;
	}
	num = n;
	if (num < 0)
	{
		if (!minus)
			ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd, f, minus);
		num %= 10;
	}
	if (num < 10)
		ft_putchar_fd(num + '0', 1);
}
