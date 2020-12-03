/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:31:46 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 21:27:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_flag_value(const char **pp_fm)
{
	if (*(*pp_fm - 1) != '.')
		flag_lst.width = ft_atoi(*pp_fm, 'd');
	if (*(*pp_fm - 1) != '.')
		*pp_fm += ft_dlen(flag_lst.width) - 1;
	if (*(*pp_fm - 1) == '.')
		flag_lst.pre = ft_atoi(*pp_fm, 'd');
	if (*(*pp_fm - 1) == '.')
		*pp_fm += ft_dlen(flag_lst.pre) - 1;
}

void			get_flag(const char **pp_fm, va_list ap)
{
	while ((**pp_fm == '-' || **pp_fm == '0' || **pp_fm == '*' || \
		**pp_fm == '.' || (**pp_fm >= '0' && **pp_fm <= '9')) && \
		pp_fm != NULL && *pp_fm != NULL)
	{
		if (**pp_fm == '-')
			flag_lst.is_left = 1;
		else if (**pp_fm == '0')
			flag_lst.is_zero = 1;
		else if (**pp_fm >= '0' && **pp_fm <= '9')
			get_flag_value(pp_fm);
		else if (**pp_fm == '*')
		{
			if (*(*pp_fm - 1) == '.')
				flag_lst.p_wild = va_arg(ap, int);
			else
				flag_lst.w_wild = va_arg(ap, int);
		}
		*pp_fm += 1;
	}
}

long long		get_arg(const char format, va_list ap, char **pp_arg,\
				long long ld)
{
	if (format == 'c' || format == 'd' || format == 'i' || format == 'u')
		ld = va_arg(ap, int);
	else if (format == 's')
		*pp_arg = va_arg(ap, char *);
	else if (format == 'x')
		ft_itob(va_arg(ap, int), "0123456789abcdef", pp_arg, format);
	else if (format == 'X')
		ft_itob(va_arg(ap, int), "0123456789ABCDEF", pp_arg, format);
	else if (format == 'p')
		ft_itob(va_arg(ap, unsigned long long), "0123456789abcdef", pp_arg,
		format);
	else if (format == '%')
		ld = '%';
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		g_arglen = ft_strlen(*pp_arg);
		if (format == 'p')
			g_arglen += 2;
	}
	else if (format == 'd' || format == 'i' || format == 'u')
		g_arglen = ft_dlen(ld);
	else if (format == 'c' || format == '%')
		g_arglen = 1;
	return (ld);
}
#include <stdio.h>

void			print_arg(const char format, char *p_arg, const long long ld)
{
	if (format == 's' || format == 'x' || format == 'X' || format == 'p')
	{
		if (format == 'p')
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(p_arg, 1);
		}
		if ((size_t)g_arglen == ft_strlen(p_arg))
			ft_putstr_fd(p_arg, 1);
	}
	else if (format == 'c' || format == '%')
		ft_putchar_fd(ld, 1);
	else if (format == 'd' || format == 'i' || format == 'u')
		ft_putnbr_fd(ld, 1);
	ft_print_flag(format, p_arg);
}

int				ft_printf(const char *format, ...)
{
	long long	ld;
	char		*p_arg;
	va_list		ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			get_flag(&format, ap);
			ld = get_arg(*format, ap, &p_arg, ld);
			ft_print_flag(*format, p_arg);
			print_arg(*format, p_arg, ld);
			ft_free(*format, (void **)&p_arg);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (g_count);
}

#include <stdio.h>

int		main(void)
{
	char *s = "asdf";
	
	printf("%x\n", -1234);
	ft_printf("%x\n", -1234);
	return (0);
}