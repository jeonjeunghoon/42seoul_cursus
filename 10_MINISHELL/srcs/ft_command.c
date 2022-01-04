/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/04 16:03:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	bulitin_command(t_mini *mini)
{
	return ;
}

char	*shell_command(t_mini *mini, char *cmd)
{
	int		i;
	int		fd;
	char	*absolute_path_cmd;
	char	*tmp_cmd;

	absolute_path_cmd = ft_strjoin("/", cmd);
	fd = 0;
	i = 0;
	while (mini->envp[i])
	{
		tmp_cmd = ft_strjoin(mini->envp[i], absolute_path_cmd);
		fd = access(tmp_cmd, X_OK);
		if (fd != -1)
		{
			free(absolute_path_cmd);
			return (tmp_cmd);
		}
		close(fd);
		free(tmp_cmd);
		i++;
	}
	free(absolute_path_cmd);
	return (NULL);
}

int	mini_command(t_mini *mini, char *cmd)
{
	// if ((ft_strncmp(cmd, "echo", 5)) == 0)
	// 	ft_echo();
	if ((ft_strncmp(cmd, "cd", 3)) == 0)
		ft_cd();
	else if ((ft_strncmp(cmd, "pwd", 4)) == 0)
		ft_pwd();
	else if ((ft_strncmp(cmd, "export", 7)) == 0)
		ft_export();
	else if ((ft_strncmp(cmd, "unset", 6)) == 0)
		ft_unset();
	else if ((ft_strncmp(cmd, "env", 4)) == 0)
		ft_env();
	// else if ((ft_strncmp(cmd, "exit", 5)) == 0)
	// 	ft_exit();
	if (mini->minicmd_flag == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_command(t_mini *mini, char *input, char **strs)
{
	if (input[0] == '\0')
		return (ENTER);
	if ((mini_command(mini, strs[0])) == TRUE)
	{
		mini->minicmd_flag = FALSE;
		return (0);
	}
	else
	{
		mini->cmd = shell_command(mini, strs[0]);
		if (mini->cmd == NULL)
		{
			printf("-bash: %s: command not found\n", strs[0]);
			return (0);
		}
		execve(mini->cmd, &(strs[1]), NULL);
	}
	free(mini->cmd);
	mini->cmd = NULL;
	return (0);
}
