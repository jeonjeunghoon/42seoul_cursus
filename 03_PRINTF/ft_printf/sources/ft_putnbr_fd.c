/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:14:28 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:53:07 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	if (f == 'u')
	{
		un_putnbr((unsigned int)n, fd, f);
		return ;
	}
	if (n < 0)
	{
		if (!minus)
			ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, f, minus);
		n %= 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}
