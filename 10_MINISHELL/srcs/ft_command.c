/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:43:25 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 11:52:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	mini_command(t_mini *mini, char *cmd, t_argv *argv)
{
	if ((ft_strncmp(cmd, "echo", 5)) == 0)
		ft_echo(argv);
	else if ((ft_strncmp(cmd, "cd", 3)) == 0)
		ft_cd(mini, argv);
	else if ((ft_strncmp(cmd, "pwd", 4)) == 0)
		ft_pwd(argv);
	else if ((ft_strncmp(cmd, "env", 4)) == 0)
		ft_env(mini, argv);
	else if ((ft_strncmp(cmd, "export", 7)) == 0)
		ft_export(mini, argv);
	else if ((ft_strncmp(cmd, "unset", 6)) == 0)
		ft_unset(mini, argv);
	else if ((ft_strncmp(cmd, "exit", 5)) == 0)
		ft_exit(argv);
	else
		return (FALSE);
	return (TRUE);
}

int	pid_zero(t_mini *mini, t_argv *argv, \
				char **cmd_path, t_bool is_child)
{
	if (argv->is_pipe == TRUE)
	{
		dup2(mini->pipe_fd[WRITE], STDOUT_FILENO);
		close(mini->pipe_fd[READ]);
	}
	if (set_redirect(argv) == ERROR)
		return (ERROR);
	if (mini_command(mini, argv->argv[0], argv) == FALSE)
	{
		create_cmdpath(mini, argv->argv[0], cmd_path);
		exe_cmd(mini, *cmd_path, argv, is_child);
		ft_free(cmd_path);
	}
	if (is_child == TRUE)
		exit(g_sig->exitnum);
	return (0);
}

void	pid_not_zero(t_mini *mini, t_argv *argv, int pid, int *stat_loc)
{
	waitpid(pid, stat_loc, 0x00000002);
	if (argv->is_pipe == TRUE)
	{
		close(mini->pipe_fd[WRITE]);
		dup2(mini->pipe_fd[READ], STDIN_FILENO);
	}
	exit_num_set(ft_wexitstatus(*stat_loc));
}

int	pipe_set(t_mini *mini, t_argv *argv, int *pid, t_bool *is_child)
{
	if (argv->is_pipe == TRUE)
	{
		if (pipe(mini->pipe_fd) == ERROR)
			return (ERROR);
	}
	if (argv->is_pipe == TRUE || argv->was_pipe == TRUE)
	{
		*is_child = TRUE;
		*pid = fork();
	}
	return (0);
}

int	ft_command(t_mini *mini, t_argv *argv)
{
	char	*cmd_path;
	pid_t	pid;
	int		stat_loc;
	t_bool	is_child;

	cmd_path = NULL;
	pid = 0;
	is_child = FALSE;
	g_sig->type = EXECVE;
	ft_signal();
	if (pipe_set(mini, argv, &pid, &is_child) == ERROR)
		return (ERROR);
	if (pid > 0)
		pid_not_zero(mini, argv, pid, &stat_loc);
	else if (pid == 0)
		if (pid_zero(mini, argv, &cmd_path, is_child) == ERROR)
			return (ERROR);
	return (0);
}
