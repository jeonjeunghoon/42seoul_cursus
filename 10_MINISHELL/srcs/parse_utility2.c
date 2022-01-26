/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utility2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:16:26 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/26 14:16:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	argv_lst_init(t_argv **str, t_argv **stream, int *size)
{
	*size = 0;
	*str = NULL;
	*stream = NULL;
}
