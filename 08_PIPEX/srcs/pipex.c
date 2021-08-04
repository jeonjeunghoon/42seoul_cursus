/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/04 16:48:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	connect_pipe(int *fildes, int io)
{
	dup2(fildes[io], io);
	close(fildes[0]);
	close(fildes[1]);
}

int	pipex(t_arg *arg, int *fildes, char **envp, pid_t *pid)
{
	if (*pid > 0)
	{
		waitpid(*pid, NULL, WNOWAIT);
		if (arg->cmd2 == NULL)
			return (IS_ERROR);
		connect_pipe(fildes, FD_EXIT);
		redirect_out(arg->outfile);
		if ((execve(arg->cmd2, arg->cmd_arg2, envp)) == IS_ERROR)
			perror(arg->cmd2);
	}
	else if (*pid == 0)
	{
		redirect_in(arg->infile);
		if (arg->cmd1 == NULL)
			return (IS_ERROR);
		connect_pipe(fildes, FD_ENTRY);
		if ((execve(arg->cmd1, arg->cmd_arg1, envp)) == IS_ERROR)
			perror(arg->cmd1);
	}
	return (IS_ERROR);
}
