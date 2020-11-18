/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:53:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/18 13:56:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_atoi(const char *str);
unsigned int	ft_atou(char *str);
void			ft_putnbr_fd(long long n, long long fd);
void			ft_putnbr_base(int nbr, char *base);
unsigned int	ft_toa_len(unsigned int n);
char			*ft_itoa(int num);
char			*ft_utoa(unsigned int num);

#endif