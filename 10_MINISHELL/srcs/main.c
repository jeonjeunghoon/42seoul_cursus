/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/13 12:59:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	lst_free(t_list *lst)
{
	t_list	*head;
	t_token	*token;

	while (lst != NULL)
	{
		head = NULL;
		token = NULL;
		head = lst;
		token = head->content;
		lst = lst->next;
		free(token->token);
		token->token = NULL;
		free(token);
		token = NULL;
		free(head);
	}
}

void	clear_resource(t_mini *mini)
{
	free(mini->prompt->locate);
	free(mini->prompt->prompt);
	free(mini->prompt->envp);
	lst_free(mini->input->token_lst);
	free(mini->input->user_input);
}

int	minishell_init(t_mini *mini)
{
	mini->prompt->locate = NULL;
	mini->prompt->prompt = NULL;
	mini->prompt->envp = NULL;
	mini->prompt->path_of_cmd = NULL;
	mini->input->token_lst = NULL;
	mini->input->argv_lst = NULL;
	mini->input->user_input = NULL;
	mini->flag->single_flag = FALSE;
	mini->flag->double_flag = FALSE;
	mini->flag->minicmd_flag = FALSE;

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
		if (mini->input->user_input[0] != '\0')
		{
			if (ft_parsing(mini) == ERROR)
				ft_error();
			if (ft_signal(mini) == ERROR)
				ft_error();
			if (ft_stream(mini) == ERROR)
				ft_error();
			// if (ft_command(mini) == ERROR)
			// 	ft_error();
		}
		clear_resource(mini);
	}
	return (0);
}
