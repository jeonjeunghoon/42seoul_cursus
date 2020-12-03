/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:18:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 21:27:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

typedef struct		s_flist
{
	unsigned int	is_left;
	unsigned int	is_zero;
	int				width;
	int				pre;
	int				w_wild;
	int				p_wild;
}					t_flist;

t_flist				flag_lst;

int					ft_printf(const char *format, ...);
size_t				ft_dlen(long long digit);
void				ft_itob(unsigned long long n, char *base, char **ptr_va, char format);
void				ft_free(const char format, void **pp);
void				ft_structclear(void);
void				ft_print_flag(const char format, char *p_arg);

#endif