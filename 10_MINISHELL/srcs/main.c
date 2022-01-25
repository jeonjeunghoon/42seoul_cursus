/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 16:37:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_mini *mini)
{
	ft_two_dimension_free(&(mini->path));
	free(mini->prompt->locate);
	free(mini->prompt->prompt);
	token_free(mini->input->token_lst);
	argv_free(mini->input->argv_lst);
	free(mini->input->user_input);
}

int	minishell_init(t_mini *mini)
{
	mini->path = NULL;
	mini->cmd_path = NULL;
	mini->prompt->locate = NULL;
	mini->prompt->prompt = NULL;
	mini->input->token_lst = NULL;
	mini->input->argv_lst = NULL;
	mini->input->user_input = NULL;
	mini->flag->single_flag = FALSE;
	mini->flag->double_flag = FALSE;
	return (0);
}

int	memory_allocation(t_mini **mini, char **envp)
{
	int	i;
	int	size;

	(*mini) = (t_mini *)malloc(sizeof(t_mini));
	size = ft_two_dimension_size(envp);
	(*mini)->envp = (char **)malloc(sizeof(char *) * (size + 1));
	(*mini)->envp[size] = NULL;
	i = 0;
	while (envp[i])
	{
		(*mini)->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	(*mini)->prompt = (t_prompt *)malloc(sizeof(t_prompt));
	(*mini)->input = (t_input *)malloc(sizeof(t_input));
	(*mini)->flag = (t_flag *)malloc(sizeof(t_flag));
	if (tcgetattr(STDIN_FILENO, &((*mini)->term)) == -1)
		return (ERROR);
	((*mini)->term).c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &((*mini)->term)) == -1)
		return (ERROR);
	if ((*mini) == NULL || (*mini)->prompt == NULL || \
		(*mini)->input == NULL || (*mini)->flag == NULL)
		return (ERROR);
	return (0);
}

int	main(int argc, const char **argv, char **envp)
{
	t_mini	*mini;

	if (memory_allocation(&mini, envp) == ERROR)
		ft_error();
	ft_signal();
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
			if (ft_stream(mini) == ERROR)
				ft_error();
			if (ft_command(mini, mini->input->argv_lst) == ERROR)
				ft_error();
		}
		clear_resource(mini);
	}
	return (0);
}
