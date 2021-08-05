/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/05 17:37:32 by jeunjeon         ###   ########.fr       */
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
		if (arg->cmd2 == NULL)
			return (IS_ERROR);
		set_pipe_exit(fildes);
		redirect_out(arg->outfile);
		if ((execve(arg->cmd2, arg->cmd_arg2, envp)) == IS_ERROR)
			perror(arg->cmd2);
	}
	else if (*pid == 0)
	{
		redirect_in(arg->infile);
		if (arg->cmd1 == NULL)
			return (IS_ERROR);
		set_pipe_entry(fildes);
		if ((execve(arg->cmd1, arg->cmd_arg1, envp)) == IS_ERROR)
			perror(arg->cmd1);
	}
	return (IS_ERROR);
}
