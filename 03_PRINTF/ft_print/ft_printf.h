/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:18:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 17:33:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# include <stdio.h>

typedef struct		s_flist
{
	unsigned int	is_left;
	unsigned int	is_zero;
	int				is_minus;
	int				width;
	int				pre;
	int				w_wild;
	int				p_wild;
}					t_flist;

t_flist				flst;

int					ft_printf(const char *format, ...);
size_t				ft_dlen(long long digit);
void				ft_itob(unsigned long long n, char *base, char **ptr_va, \
					char format);
void				ft_free(const char format, void **pp);
void				ft_structclear(void);
void				ft_print_flag(const char format);
void				ft_get_size(const char format, char *p_arg);
void				ft_globalclear(void);

#endif