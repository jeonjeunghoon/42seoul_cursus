/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/07 15:47:29 by jeunjeon         ###   ########.fr       */
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

int	mini_command(t_mini *mini, char **argv)
{
	// if ((ft_strncmp(argv[0], "echo", 5)) == 0)
	// 	ft_echo(mini, argv);
	if ((ft_strncmp(argv[0], "cd", 3)) == 0)
		ft_cd(mini, argv);
	else if ((ft_strncmp(argv[0], "pwd", 4)) == 0)
		ft_pwd(mini, argv);
	else if ((ft_strncmp(argv[0], "export", 7)) == 0)
		ft_export(mini, argv);
	else if ((ft_strncmp(argv[0], "unset", 6)) == 0)
		ft_unset(mini, argv);
	else if ((ft_strncmp(argv[0], "env", 4)) == 0)
		ft_env(mini, argv);
	// else if ((ft_strncmp(argv[0], "exit", 5)) == 0)
	// 	ft_exit(mini, argv);
	if (mini->minicmd_flag == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_command(t_mini *mini, char *cmd, char **argv)
{
	if ((mini_command(mini, argv)) == FALSE)
	{
		mini->shell_cmd = shell_command(mini, argv[0]);
		if (mini->shell_cmd == NULL)
		{
			printf("-bash: %s: command not found\n", argv[0]);
			return (0);
		}
		execve(mini->shell_cmd, &(argv[1]), NULL);
		free(mini->shell_cmd);
		mini->shell_cmd = NULL;
	}
	mini->minicmd_flag = FALSE;
	return (0);
}
