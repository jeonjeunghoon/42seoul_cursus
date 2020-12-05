/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:14:28 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 16:33:17 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(long long n, int fd, int minus)
{
	char		c;
	long long	num;

	num = n;
	if (num < 0)
	{
		if (!minus)
			ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd, minus);
		num %= 10;
	}
	if (num < 10)
	{
		c = num + '0';
		ft_putchar_fd(c, 1);
	}
}
