/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:53:54 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/23 20:01:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

unsigned int	count;

int				ft_printf(const char *format, ...);
size_t			ft_strlen(char *s);
long long		ft_atoi(char *str, char fm);
void			ft_putnbr_fd(long long n, long long fd);
void			ft_putnbr_base(unsigned int nbr, char *base, char fm);
char			*ft_itoa(int num, char fm);

#endif