/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/27 12:16:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipe_init(int *fildes, int io)
{
	dup2(fildes[io], io);
	close(fildes[0]);
	close(fildes[1]);
}

int	pipex(t_arg *arg, int *fildes)
{
	pid_t	pid;

	if ((pipe(fildes)) == IS_ERROR)
	{
		perror("pipe");
		ft_exit(NULL);
	}
	pid = fork();
	if (pid > 0) // parents process
	{
		if ((wait(NULL)) == IS_ERROR)
			return (IS_ERROR);
		redirect_out(arg);
		pipe_init(fildes, STDIN_FILENO);
		if ((execve(arg->path2, arg->cmd_arg2, arg->cmd_envp2)) == IS_ERROR)
			perror(arg->path2);
	}
	else if (pid == 0) // child process
	{
		redirect_in(arg);
		pipe_init(fildes, STDOUT_FILENO);
		if ((execve(arg->path1, arg->cmd_arg1, arg->cmd_envp1)) == IS_ERROR)
			perror(arg->path1);
	}
	else
		return (IS_ERROR);
	return (0);
}
