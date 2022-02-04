/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_utility2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:55:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/04 16:33:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	double_ampersand(t_list *head, t_bool is_error)
{
	
}

void	double_verticalbar(t_list *head, t_bool is_error)
{
	
}

void	verticalbar(t_list *head, char *argv, int *fd, t_bool is_error)
{
	if (argv[1] == '|')
		double_verticalbar(head, is_error);
	else
	{
		
	}
}
