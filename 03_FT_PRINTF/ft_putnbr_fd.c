/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:57:27 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/13 15:12:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	num;

	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
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
	}
}
