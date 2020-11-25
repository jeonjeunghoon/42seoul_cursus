/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:53:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/25 17:15:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

unsigned int	g_count;
unsigned int	g_move;
unsigned int	g_flag;

int				ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			ft_putstr(char *s);
size_t			ft_strlen(char *s);
long long		ft_atoi(char *s, char fm);
void			ft_putnbr(long long n);
void			ft_putnbr_base(unsigned long long nbr, char *base, char fm);
char			*ft_itoa(long long num, char fm, char *s);
void			ft_spec_csdiu(char fm, va_list ap, char *s);
void			ft_spec_pxp(char fm, va_list ap, char *s);
void			ft_free(char *s);

#endif