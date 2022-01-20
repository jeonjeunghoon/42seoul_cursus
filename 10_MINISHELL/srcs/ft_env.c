/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:59 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 16:59:30 by jeunjeon         ###   ########.fr       */
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
	mini->flag->minicmd_flag = TRUE;
	if (ft_two_dimension_size(argv) != 1)
	{
		printf("minishell: %s: %s: With no options or arguments\n", argv[0], argv[1]);
		return ;
	}
	show_env(mini->envp);
	exit_num_set(EXIT_SUCCESS);
}
