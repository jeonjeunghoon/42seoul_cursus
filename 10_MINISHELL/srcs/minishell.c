/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/02 21:14:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_command(t_mini *mini, t_argv *argv)
{
	char	*cmd_path;

	cmd_path = NULL;
	if (argv->argv[0][0] == '\0')
		return (0);
	if (mini_command(mini, argv->argv[0], argv->argv) == FALSE)
	{
		cmd_path = check_cmd(mini, argv->argv[0]);
		exe_cmd(cmd_path, argv->argv, mini->path);
		if (cmd_path != NULL)
		{
			free(cmd_path);
			cmd_path = NULL;
		}
	}
	return (0);
}

// int	ft_stream(t_mini *mini)
// {
	
// 	return (0);
// }

// int	connect_redirect(char **argv)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i] != NULL)
// 	{
// 		if (argv[i][0] == '>')
// 		{
// 			if (argv[i][1] == '>')
// 			{

// 			}
// 		}
// 		if (argv[i][0] == '<')
// 		{
// 			if (argv[i][1] == '<')
// 			{
				
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	minishell(t_mini *mini)
{
	t_list	*head;

	head = mini->input->argv_lst;
	while (head != NULL)
	{
		// if (connect_redirect(((t_argv *)(head->content))->argv) == ERROR)
		// 	return (ERROR);
		// if (ft_stream(mini) == ERROR)
		// 	return (ERROR);
		ft_command(mini, head->content);
		head = head->next;
	}
	return (0);
}
