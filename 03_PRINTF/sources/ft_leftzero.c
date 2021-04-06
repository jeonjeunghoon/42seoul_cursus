/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:31:32 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_leftzero(const char **ppf)
{
	while (**ppf == '-' || **ppf == '0')
	{
		if (**ppf == '-')
		{
			g_lst.isleft = 1;
			g_lst.iszero = 0;
		}
		if (**ppf == '0' && g_lst.isleft == 0)
			g_lst.iszero = 1;
		*ppf += 1;
	}
}
