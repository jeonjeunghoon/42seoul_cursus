/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/30 18:21:16 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_format(char **c)
{
	while (!(**c == 'c' || **c == 's' || **c == 'd' || **c == 'i' || **c == 'u'
	|| **c == 'p' || **c == 'x' || *c == 'X') && *c != NULL)
		(*c)++;
}

void			get_arg(char *format, va_list ap, char **ptr_va)
{
	set_format(&format);
	ld = 0;
	if (format == 'c' || format == 'd' || format == 'i' || format == 'u')
		ld = va_arg(ap, int);
	else if (format == 's')
		*ptr_va = va_arg(ap, char *);
	if (format == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", ptr_va);
	else if (format == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", ptr_va);
	else if (format == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", ptr_va);
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		arg_len = ft_strlen(*ptr_va);
		if (format == 'p')
			arg_len += 2;
	}
	else if (format == 'd' || format == 'i' || format == 'u')
		arg_len = ft_digitlen(ld);
	else if (format == 'c' || format == '%')
		arg_len = 1;
}

void			flag_control(char *format)
{
	
}

int				ft_printf(const char *format, ...)
{
	void		*ptr_va;
	va_list 	ap;

	va_start(ap, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			arg_len = 0;
			flag_control((char *)(++format));
			get_arg((char *)(++format), ap, &ptr_va);
			// print
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
}

/*
	생각하는 구현 로직
	전역변수 arg_len에 플래그 출력갯수를 저장,
*/