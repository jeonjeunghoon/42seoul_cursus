/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:41:56 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:43:48 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		is_wild(const char **ppf, va_list ap)
{
	size_t	len;

	len = 0;
	g_lst.p = va_arg(ap, int);
	if (g_lst.p == 0)
		g_lst.p = -1;
	else if (g_lst.p < 0)
		g_lst.p = 0;
	*ppf += 1;
	return (len);
}

size_t		is_pre(const char **ppf, const char f)
{
	size_t	len;

	len = 0;
	g_lst.p = ft_atoi(*ppf, 'd');
	len = ft_numlen(g_lst.p, f);
	*ppf += len;
	return (len);
}

void		ft_precision(const char **ppf, va_list ap, const char f)
{
	size_t	len;

	len = 0;
	if (**ppf == '.')
	{
		*ppf += 1;
		while (**ppf == '0')
			*ppf += 1;
		if (**ppf >= '1' && **ppf <= '9')
			len = is_pre(ppf, f);
		else if (**ppf == '*')
			len = is_wild(ppf, ap);
		else
			g_lst.p = -1;
	}
}
