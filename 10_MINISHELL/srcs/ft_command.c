/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 00:20:10 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	create_path_bundle(t_mini *mini)
{
	char	*path_str;

	path_str = ft_getenv(mini->envp, "PATH");
	if (path_str == NULL)
		return ;
	mini->path = ft_split(path_str, ':');
}

void	check_cmd(t_mini *mini, char *cmd)
{
	struct stat	file_info;
	char		*file_path;
	char		*tmp;
	int			i;

	create_path_bundle(mini);
	if (mini->path == NULL)
		return ;
	tmp = ft_strjoin("/", cmd);
	i = 0;
	while (mini->path[i])
	{
		file_path = ft_strjoin(mini->path[i], tmp);
		if (stat(file_path, &file_info) == SUCCESS)
			break ;
		free(file_path);
		i++;
	}
	free(tmp);
	if (mini->path[i] == NULL)
		mini->cmd_path = NULL;
	else
		mini->cmd_path = file_path;
}

int	mini_command(t_mini *mini, char *cmd, char **argv)
{
	if ((ft_strncmp(cmd, "echo", 5)) == 0)
		ft_echo(mini, argv);
	else if ((ft_strncmp(cmd, "cd", 3)) == 0)
		ft_cd(mini, argv);
	else if ((ft_strncmp(cmd, "pwd", 4)) == 0)
		ft_pwd(mini, argv);
	else if ((ft_strncmp(cmd, "env", 4)) == 0)
		ft_env(mini, argv);
	else if ((ft_strncmp(cmd, "export", 7)) == 0)
		ft_export(mini, argv);
	else if ((ft_strncmp(cmd, "unset", 6)) == 0)
		ft_unset(mini, argv);
	else if ((ft_strncmp(cmd, "exit", 5)) == 0)
		ft_exit(mini, argv);
	else
		return (FALSE);
	return (TRUE);
}

void	exe_cmd(char *cmd_path, char **argv, char **envp)
{
	pid_t	pid;

	pid = 0;
	if (cmd_path == NULL)
	{
		command_not_found(argv[0]);
		return ;
	}
	pid = fork();
	if (pid > 0)
	{
		wait(0);
		g_exit_state = 0;
	}
	else if (pid == 0)
		execve(cmd_path, argv, envp);
}

int	ft_command(t_mini *mini, t_list *argv_lst)
{
	while (argv_lst != NULL)
	{
		if ((mini_command(mini, ((t_argv *)argv_lst->content)->argv[0], \
						((t_argv *)argv_lst->content)->argv)) == FALSE)
		{
			check_cmd(mini, ((t_argv *)argv_lst->content)->argv[0]);
			exe_cmd(mini->cmd_path, ((t_argv *)argv_lst->content)->argv, \
					mini->path);
			free(mini->cmd_path);
			mini->cmd_path = NULL;
		}
		argv_lst = argv_lst->next;
	}
	return (0);
}
