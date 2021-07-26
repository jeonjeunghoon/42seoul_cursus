/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/26 18:09:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipe_init(int *fd, int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}

int	pipex(t_arg *arg, int *fd, pid_t *pid)
{
	if (*pid > 0)
	{
		if ((wait(NULL)) == -1)
			return (-1);
		if ((redirect_out(arg)) == -1)
			return (-1);
		pipe_init(fd, STDIN_FILENO);
		if ((execve(arg->path2, arg->cmd_arg2, arg->cmd_envp2)) == -1)
			perror(arg->path2);
	}
	else if (*pid == 0)
	{
		if ((redirect_in(arg)) == -1)
			return (-1);
		pipe_init(fd, STDOUT_FILENO);
		if ((execve(arg->path1, arg->cmd_arg1, arg->cmd_envp1)) == -1)
			perror(arg->path1);
	}
	return (0);
}
