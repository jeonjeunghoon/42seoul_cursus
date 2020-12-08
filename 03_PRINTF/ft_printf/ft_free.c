/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:39:22 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 15:27:58 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free(const char f, void **pp)
{
	if (!(f == 'x' || f == 'X' || f == 'p' || f == 'l') \
	|| pp == NULL || *pp == NULL)
		return ;
	else if ((f == 'x' || f == 'X' || f == 'p' || f == 'l') \
	&& (pp != NULL && *pp != NULL))
	{
		if (pp != NULL && *pp != NULL)
		{
			free(*pp);
			*pp = NULL;
		}
	}
}
