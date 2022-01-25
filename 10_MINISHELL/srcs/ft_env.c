/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:59 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 16:40:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	show_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	ft_env(t_mini *mini, char **argv)
{
	if (ft_two_dimension_size(argv) != 1)
	{
		error_2(argv[0], argv[1], "With no options or arguments");
		exit_num_set(1);
		return ;
	}
	show_env(mini->envp);
	exit_num_set(g_exit_state);
}
