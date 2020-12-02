/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:56:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/02 17:10:58 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_structclear(t_flist *flag_lst)
{
	if (flag_lst == NULL)
		return ;
	else
	{
		flag_lst->is_left = 0;
		flag_lst->is_zero = 0;
		flag_lst->pre = 0;
		flag_lst->p_wild = 0;
		flag_lst->width = 0;
		flag_lst->w_wild = 0;
	}
}
