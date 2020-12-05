/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:40:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/05 15:02:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*p;
	unsigned int	u;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_flag()
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	return (g_count);
}