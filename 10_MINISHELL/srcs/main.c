/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 14:59:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_mini *mini)
{
	ft_two_dimension_free(&(mini->path));
	token_free(mini->input->token_lst);
	argv_free(mini->input->argv_lst);
	free(mini->input->user_input);
}

int	minishell_init(t_mini *mini)
{
	mini->path = NULL;
	mini->input->token_lst = NULL;
	mini->input->argv_lst = NULL;
	mini->input->user_input = NULL;
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
	i = -1;
	while (envp[++i])
		(*mini)->envp[i] = ft_strdup(envp[i]);
	(*mini)->input = (t_input *)malloc(sizeof(t_input));
	if (tcgetattr(STDIN_FILENO, &((*mini)->term)) == -1)
		return (ERROR);
	((*mini)->term).c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &((*mini)->term)) == -1)
		return (ERROR);
	if ((*mini) == NULL || (*mini)->input == NULL)
		return (ERROR);
	return (0);
}

int	main(int argc, const char **argv, char **envp)
{
	t_mini	*mini;

	if (argc != 1 || argv == NULL)
		return (0);
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
			if (ft_parsing(mini) != ERROR)
			{
				if (minishell(mini) == ERROR)
					ft_error();
			}
		}
		clear_resource(mini);
	}
	return (0);
}
