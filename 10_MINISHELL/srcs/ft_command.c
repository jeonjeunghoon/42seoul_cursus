/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 16:55:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		if (fd != ERROR)
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

int	mini_command(t_mini *mini, char *cmd, char **argv)
{
	if ((ft_strncmp(cmd, "echo", 5)) == 0)
		ft_echo(mini, argv);
	if ((ft_strncmp(cmd, "cd", 3)) == 0)
		ft_cd(mini, argv);
	else if ((ft_strncmp(cmd, "pwd", 4)) == 0)
		ft_pwd(mini, argv);
	else if ((ft_strncmp(cmd, "export", 7)) == 0)
		ft_export(mini, argv);
	else if ((ft_strncmp(cmd, "unset", 6)) == 0)
		ft_unset(mini, argv);
	else if ((ft_strncmp(cmd, "env", 4)) == 0)
		ft_env(mini, argv);
	else if ((ft_strncmp(cmd, "exit", 5)) == 0)
		ft_exit(mini, argv);
	if (mini->minicmd_flag == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_command(t_mini *mini)
{
	pid_t	pid;
	char	*path_of_cmd;

	path_of_cmd = NULL;
	if (head->is_head == TRUE)
		head = head->next;
	while (head != NULL)
	{
		if ((mini_command(mini, head->argv[0], head->argv)) == FALSE)
		{
			path_of_cmd = shell_command(mini, head->argv[0]);
			if (path_of_cmd == NULL)
			{
				command_not_found(head->argv[0]);
				return (0);
			}
			pid = fork();
			if (pid > 0)
				wait(0);
			else if (pid == 0)
			{
				execve(path_of_cmd, head->argv, mini->envp);
				exit(0);
			}
			free(path_of_cmd);
			path_of_cmd = NULL;
		}
		mini->minicmd_flag = FALSE;
		head = head->next;
	}
	return (0);
}
