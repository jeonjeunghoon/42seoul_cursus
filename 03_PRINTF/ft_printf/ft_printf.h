/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:18:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:42:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct			s_list
{
	unsigned int		isleft;
	unsigned int		iszero;
	int					isminus;
	int					minus;
	int					p;
	int					w;
	long long			n;
	unsigned long long	ull;
}						t_list;

t_list					g_lst;

int						ft_printf(const char *format, ...);
void					ft_leftzero(const char **ppf);
size_t					ft_numlen(long long num, const char f);
void					ft_except(const char f);
void					ft_width(const char **ppf, va_list ap, const char f);
void					ft_precision(const char **ppf, va_list ap, \
						const char f);
void					ft_itob(unsigned long long n, char *p_base, \
						char **pp, char f);
void					ft_free(const char f, void **pp);
void					ft_structclear(void);
int						ft_print_zero(int i);
void					ft_print_left(const char f);
void					ft_leftflag(const char f);
void					ft_printflag(const char f);
void					ft_print_alpha(void);
void					ft_print_num(const char f);
void					ft_get_size(const char f, char *p);
void					ft_globalclear(void);

#endif
