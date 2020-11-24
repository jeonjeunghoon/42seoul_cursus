/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:53:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/24 12:42:28 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

unsigned int	g_count;

int				ft_printf(const char *format, ...);
size_t			ft_strlen(char *s);
long long		ft_atoi(char *s, char fm);
void			ft_putnbr_fd(long long n, int fd);
void			ft_putnbr_base(unsigned long long nbr, char *base, char fm);
char			*ft_itoa(long long num, char fm, char *s);
void			ft_spec_csdiu(char fm, va_list ap, char *s);
void			ft_spec_pxp(char fm, va_list ap, char *s);
void			ft_free(char *s);

#endif