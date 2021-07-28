/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/28 21:46:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	connect_pipe(int *fildes, int io)
{
	dup2(fildes[io], io);
	close(fildes[0]);
	close(fildes[1]);
}

int	pipex(t_arg *arg, int *fildes)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		if ((wait(NULL)) == IS_ERROR)
			return (IS_ERROR);
		connect_pipe(fildes, FD_EXIT);
		redirect_out(arg);
		if ((execve(arg->cmd2, arg->cmd_arg2, arg->cmd_envp2)) == IS_ERROR)
			perror(arg->cmd2);
	}
	else if (pid == 0)
	{
		redirect_in(arg);
		connect_pipe(fildes, FD_ENTRY);
		if ((execve(arg->cmd1, arg->cmd_arg1, arg->cmd_envp1)) == IS_ERROR)
			perror(arg->cmd1);
	}
	else
		return (IS_ERROR);
	return (0);
}
