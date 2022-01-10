/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 16:59:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_mini *mini)
{
	t_token	*tmp;

	free(mini->prompt->locate);
	free(mini->prompt->prompt);
	free(mini->prompt->envp);
	free(mini->input->user_input);
	// tmp = NULL;
	// while (*head != NULL)
	// {
	// 	tmp = *head;
	// 	*head = (*head)->next;
	// 	if (tmp->cmdline != NULL)
	// 		ft_two_dimension_free(tmp->cmdline);
	// 	tmp->cmdline = NULL;
	// 	free(tmp);
	// }
	free(mini->input->token);
}

int	minishell_init(t_mini *mini)
{
	mini->prompt->locate = NULL;
	mini->prompt->prompt = NULL;
	mini->prompt->envp = NULL;
	mini->prompt->path_of_cmd = NULL;
	mini->input->user_input = NULL;
	mini->input->token = NULL;
	mini->flag->minicmd_flag = FALSE;
	mini->flag->continue_flag = FALSE;

	// envp_str = getenv("PATH");
	// if (envp_str == NULL)
	// 	return (ERROR);
	// mini->prompt->envp = ft_split(envp_str, ':');
	// if (mini->prompt->envp == NULL)
	// 	return (ERROR);
	
	return (0);
}

int	main(int argc, const char **argv)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	mini->prompt = (t_prompt *)malloc(sizeof(t_prompt));
	mini->input = (t_input *)malloc(sizeof(t_input));
	mini->flag = (t_flag *)malloc(sizeof(t_flag));
	if (mini == NULL || mini->prompt == NULL || \
		mini->input == NULL || mini->flag == NULL)
		ft_error();
	while (TRUE)
	{
		if (minishell_init(mini) == ERROR)
			ft_error();
		if (ft_prompt(mini) == ERROR)
			ft_error();
		if (ft_parsing(mini) == ERROR)
			ft_error();
		if (ft_signal(mini) == ERROR)
			ft_error();
		// if (ft_command(mini) == ERROR)
		// 	ft_error();
		clear_resource(mini);
	}
	return (0);
}
