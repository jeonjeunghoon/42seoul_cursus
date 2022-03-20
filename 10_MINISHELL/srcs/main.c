/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 16:07:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_mini *mini)
{
	ft_two_dimension_free(&(mini->path));
	token_free(mini->input->token_lst);
	argv_free(mini->input->argv_lst);
	ft_free(&mini->input->user_input);
	g_sig->signum = 0;
	g_sig->type = BASIC;
	unlink(".heredoc_tmp");
}

void	minishell_init(t_mini *mini)
{
	mini->path = NULL;
	mini->input->token_lst = NULL;
	mini->input->argv_lst = NULL;
	mini->input->user_input = NULL;
	mini->wild_chk = 0;
	g_sig->signum = 0;
	g_sig->type = BASIC;
	rl_catch_signals = 0;
	ft_signal();
	unlink(".heredoc_tmp");
}

int	memory_allocation(t_mini **mini, char **envp)
{
	int	i;
	int	size;

	(*mini) = (t_mini *)malloc(sizeof(t_mini));
	size = ft_two_dimension_size(envp);
	(*mini)->export_list = (char **)malloc(sizeof(char *) * (size + 1));
	(*mini)->env_list = (char **)malloc(sizeof(char *) * (size + 1));
	(*mini)->export_list[size] = NULL;
	(*mini)->env_list[size] = NULL;
	i = 0;
	while (envp[i])
	{
		(*mini)->export_list[i] = ft_strdup(envp[i]);
		(*mini)->env_list[i] = ft_strdup(envp[i]);
		i++;
	}
	(*mini)->input = (t_input *)malloc(sizeof(t_input));
	(*mini)->sig = (t_sig *)malloc(sizeof(t_sig));
	g_sig = (*mini)->sig;
	g_sig->exitnum = 0;
	if ((*mini) == NULL || (*mini)->input == NULL || (*mini)->sig == NULL)
		return (ERROR);
	return (0);
}

int	main(int argc, const char **argv, char **envp)
{
	t_mini	*mini;

	if (argc != 1 || argv == NULL)
		return (0);
	if (memory_allocation(&mini, envp) == ERROR)
	{
		printf("Allocation error\n");
		exit(1);
	}
	while (TRUE)
	{
		minishell_init(mini);
		if (ft_prompt(mini) == ERROR)
		{
			printf("Prompt error\n");
			exit(1);
		}
		if (mini->input->user_input[0] != '\0')
		{
			if (ft_parsing(mini) != ERROR)
				minishell(mini);
		}
		clear_resource(mini);
	}
	return (0);
}
