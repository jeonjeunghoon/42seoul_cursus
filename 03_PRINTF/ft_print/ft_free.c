/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:39:22 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/03 16:12:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free(const char format, void **pp)
{
	if (!(format == 'x' || format == 'X' || format == 'p' || format == 'l')
	|| pp == NULL || *pp == NULL)
		return ;
	else if ((format == 'x' || format == 'X' || format == 'p' || format == 'l')
	&& (pp != NULL && *pp != NULL))
	{
		if (pp != NULL && *pp != NULL)
		{
			free(*pp);
			*pp = NULL;
		}
	}
}
