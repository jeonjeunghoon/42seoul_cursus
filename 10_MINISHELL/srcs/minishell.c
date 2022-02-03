/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 16:35:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_command(t_mini *mini, char **argv)
{
	char	*cmd_path;

	cmd_path = NULL;
	if (argv[0][0] == '\0')
		return (0);
	if (mini_command(mini, argv[0], argv) == FALSE)
	{
		cmd_path = check_cmd(mini, argv[0]);
		exe_cmd(cmd_path, argv, mini->path);
		if (cmd_path != NULL)
		{
			free(cmd_path);
			cmd_path = NULL;
		}
	}
	return (0);
}

// char	**set_stream(t_list **head)
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
	char	**argv;

	head = mini->input->argv_lst;
	argv = NULL;
	while (head != NULL)
	{
		// argv = set_stream(&head);
		argv = ((t_argv *)(head->content))->argv;
		ft_command(mini, argv);
		head = head->next;
		argv = NULL;
	}
	return (0);
}
