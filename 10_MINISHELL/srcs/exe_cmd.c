/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:14:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 12:00:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	remove_redirection(t_argv *argv)
{
	char	**new_argv;
	int		len;
	int		i;
	int		j;

	len = ft_two_dimension_size(argv->argv);
	i = -1;
	while (argv->argv[++i])
		if (argv->argv[i][0] == '>' || argv->argv[i][0] == '<')
			len -= 2;
	new_argv = (char **)malloc(sizeof(char *) * (len + 1));
	new_argv[len] = NULL;
	i = 0;
	j = 0;
	while (i < len && argv->argv[j])
	{
		if (argv->argv[j][0] == '>' || argv->argv[j][0] == '<')
			j += 2;
		new_argv[i] = ft_strdup(argv->argv[j]);
		i++;
		j++;
	}
	ft_two_dimension_free(&argv->argv);
	argv->argv = new_argv;
}

int	set_redirect(t_argv *argv)
{
	int		i;

	if (argv->is_redirect == FALSE)
		return (0);
	i = 0;
	while (argv->argv[i])
	{
		if (append(argv->argv[i], argv->argv[i + 1], &i) == ERROR)
			return (ERROR);
		if (ltor(argv->argv[i], argv->argv[i + 1], &i) == ERROR)
			return (ERROR);
		if (heredoc(argv->argv[i], &i) == ERROR)
			return (ERROR);
		if (rtol(argv->argv[i], argv->argv[i + 1], &i) == ERROR)
			return (ERROR);
		i++;
	}
	remove_redirection(argv);
	return (0);
}

void	exe_child(t_mini *mini, char **argv, char *cmd_path, char **envp)
{
	if (argv[0][0] == '\0')
		exit_num_set(0);
	else if (cmd_path == NULL)
		error_1(cmd_path, "No such file or directory", 127);
	else if (execve(cmd_path, argv, envp) == ERROR)
	{
		if (cmd_path[0] == '/' || mini->path == NULL)
			error_1(cmd_path, "No such file or directory", 127);
		else if (errno == 2)
			error_1(cmd_path, "command not found", 127);
		else if (errno == 13)
			error_1(cmd_path, "is a directory", 126);
		else
			ft_error(strerror(errno), 1);
	}	
	exit(g_sig->exitnum);
}

void	exe_cmd(t_mini *mini, char *cmd_path, \
				t_argv *argv, t_bool is_child)
{
	pid_t	pid;
	int		stat_loc;

	pid = 0;
	if (is_child == FALSE)
		pid = fork();
	rl_catch_signals = 1;
	if (pid > 0)
	{
		waitpid(pid, &stat_loc, 0x00000002);
		unlink(".heredoc_tmp");
		if (ft_wifexited(stat_loc) == TRUE)
			exit_num_set(ft_wstopsig(stat_loc));
	}
	else if (pid == 0)
		exe_child(mini, argv->argv, cmd_path, mini->export_list);
}
