/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:18:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/06 20:12:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

typedef struct		s_list
{
	unsigned int	is_left;
	unsigned int	is_zero;
	int				is_minus;
	int				minus;
	int				p;
	int				w;
	unsigned int	n;
}					t_list;

t_list					l;

int					ft_printf(const char *format, ...);
void				ft_left_or_zero(const char **ppf);
size_t				ft_digitlen(long long digit, const char f);
void				ft_except(const char f);
void				ft_width(const char **ppf, va_list ap, const char f);
void				ft_precision(const char **ppf, va_list ap, const char f);
void				ft_itob(unsigned long long n, char *base, char **ptr_va, \
					char format);
void				ft_free(const char format, void **pp);
void				ft_structclear(void);
int					ft_print_zero(int i);
void				ft_print_left(const char f);
void				ft_leftflag(const char f);
void				ft_printflag(const char f);
void				ft_print_alpha(void);
void				ft_print_num(const char f);
void				ft_get_size(const char f, char *p);
void				ft_globalclear(void);

#endif