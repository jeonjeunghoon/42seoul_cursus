/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:57:53 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 11:56:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	create_path_bundle(t_mini *mini)
{
	char	*path_str;

	path_str = ft_getenv(mini->export_list, "PATH");
	if (path_str == NULL)
		return ;
	if (mini->path == NULL)
		mini->path = ft_split(path_str, ':');
}

void	set_relative_path(t_mini *mini, char **cmd_path, char *cmd)
{
	char		*tmp;
	int			i;
	struct stat	file_info;

	create_path_bundle(mini);
	if (mini->path == NULL)
	{
		*cmd_path = ft_strdup(cmd);
		return ;
	}
	tmp = ft_strjoin("/", cmd);
	i = 0;
	while (mini->path[i])
	{
		*cmd_path = ft_strjoin(mini->path[i], tmp);
		if (stat(*cmd_path, &file_info) == SUCCESS)
		{
			ft_free(&tmp);
			return ;
		}
		ft_free(cmd_path);
		i++;
	}
	ft_free(&tmp);
	*cmd_path = ft_strdup(cmd);
}

void	create_cmdpath(t_mini *mini, char *cmd, char **cmd_path)
{
	if (cmd[0] == '/')
		*cmd_path = ft_strdup(cmd);
	else
		set_relative_path(mini, cmd_path, cmd);
}
