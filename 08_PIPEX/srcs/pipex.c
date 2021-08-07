/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/07 17:31:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	set_pipe_exit(int *fildes)
{
	dup2(fildes[FD_EXIT], FD_EXIT);
	close(fildes[FD_ENTRY]);
}

void	set_pipe_entry(int *fildes)
{
	dup2(fildes[FD_ENTRY], FD_ENTRY);
	close(fildes[FD_EXIT]);
}

int	pipex(t_arg *arg, int *fildes, char **envp, pid_t *pid)
{
	if (*pid > 0)
	{
		waitpid(*pid, NULL, WNOHANG);
		set_pipe_exit(fildes);
		redirect_out(arg->outfile);
		execve(arg->cmd2, arg->cmd_arg2, envp);
	}
	else if (*pid == 0)
	{
		redirect_in(arg->infile);
		set_pipe_entry(fildes);
		execve(arg->cmd1, arg->cmd_arg1, envp);
	}
	return (IS_ERROR);
}
