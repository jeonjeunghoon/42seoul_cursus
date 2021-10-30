/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:03:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/01 15:24:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *msg, int is_error)
{
	write(1, msg, ft_strlen(msg));
	if (is_error == 0)
		exit(0);
	else if (is_error == 1)
		exit(1);
}
