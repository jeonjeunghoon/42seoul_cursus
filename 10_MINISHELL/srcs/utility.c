/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 15:51:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_msg(char *input, char *error_msg)
{
	printf("%s: %s\n", input, error_msg);
}

void	error_func(t_mini *mini)
{
	exit(1);
}
