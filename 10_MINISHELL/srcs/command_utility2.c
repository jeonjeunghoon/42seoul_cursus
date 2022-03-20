/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utility3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:18:14 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/02 17:36:17 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	load_origin_fd(t_mini *mini)
{
	dup2(mini->origin_fd[0], STDIN_FILENO);
	dup2(mini->origin_fd[1], STDOUT_FILENO);
}

void	save_origin_fd(t_mini *mini)
{
	pipe(mini->origin_fd);
	dup2(STDIN_FILENO, mini->origin_fd[0]);
	dup2(STDOUT_FILENO, mini->origin_fd[1]);
}
