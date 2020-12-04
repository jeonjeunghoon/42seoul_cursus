/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:47 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 18:55:43 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_zero(int i)
{
	while (i > 0 && i != 0)
	{
		ft_putchar_fd('0', 1);
		i--;
	}
	return (i);
}

void		ft_exception(const char f)
{
	if (flst.pre == -1)
		g_arglen = 0;
	else
	{
		flst.pre = flst.pre > flst.p_wild ? flst.pre : flst.p_wild;
		if (g_arglen > flst.pre && f == 's')
			g_arglen = flst.pre;
		else if (f == 'i' || f == 'd' || f == 'u')
		{
			if (g_ld < 0)
			{
				ft_putchar_fd('-', 1);
				g_minuspre = 1;
				g_arglen--;
			}
			flst.pre = flst.pre > g_arglen ? flst.pre - g_arglen - flst.is_minus : g_arglen - flst.pre - flst.is_minus;
			print_zero(flst.pre);
			flst.width = flst.width > flst.w_wild ? flst.width - flst.pre - flst.is_minus : flst.w_wild - flst.pre - flst.is_minus; // 마지막 수정: 마이너스 붙였따
		}
	}
	flst.p_wild = 0;
	flst.pre = 0;
}

void		is_alpha(void)
{
	int		i;

	i = 0;
	if (flst.pre == -1)
		return ;
	if ((flst.width > g_arglen) || (flst.w_wild > g_arglen))
	{
		i = flst.width > flst.w_wild ? flst.width : flst.w_wild;
		i -= g_arglen;
		if (flst.is_zero)
			i = print_zero(i);
		while (i--)
			ft_putchar_fd(' ', 1);
	}
}

void		is_num(void)
{
	int		i;

	i = 0;
	if ((flst.width > g_arglen) || (flst.w_wild > g_arglen))
	{
		i = flst.width > flst.w_wild ? flst.width : flst.w_wild;
		i -= g_arglen > (flst.pre + flst.p_wild) ? (g_arglen + flst.is_minus) : (flst.pre + flst.p_wild + flst.is_minus);
		if (flst.is_zero)
		{
			if (g_ld < 0)
			{
				ft_putchar_fd('-', 1);
				g_minuspre = 1;
			}
			i = print_zero(i);
		}
		else if (!flst.is_zero && i > 0)
		{
			while (i--)
				ft_putchar_fd(' ', 1);
		}
	}
	if ((flst.pre > g_arglen) || (flst.p_wild > g_arglen))
	{
		i = flst.pre > flst.p_wild ? flst.pre : flst.p_wild;
		if (g_ld < 0)
		{
			ft_putchar_fd('-', 1);
			g_minuspre = 1;
			g_arglen--;
		}
		print_zero(i - flst.is_minus - g_arglen);
	}
}

void		ft_print_flag(const char f)
{
	if (g_ld < 0)
		flst.is_minus = 1;
	if (flst.pre || flst.p_wild)
		flst.is_zero = 0;
	if (flst.is_left)
	{
		if ((flst.pre || flst.p_wild) && f != 'c')
			ft_exception(f);
		flst.is_left = 0;
		flst.is_zero = 0;
	}
	else if (!(flst.is_left))
	{
		if (((flst.pre) || (flst.p_wild)) && f == 's')
			ft_exception(f);
		if (f == 'c' || f == 's' || f == '%')
			is_alpha();
		else if (f == 'd' || f == 'i' || f == 'u' \
		|| f == 'x' || f == 'X' || f == 'p')
			is_num();
		ft_structclear();
	}
}

/*

- 일 때 빈칸이 하나 더 나옴
+ 일 때 0이 하나 더 나오고 빈칸은 하나가 안나옴

*/