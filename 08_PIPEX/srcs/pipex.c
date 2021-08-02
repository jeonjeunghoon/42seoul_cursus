/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:45:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/02 22:43:17 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// int	clear_temp(void)
// {
// 	int	fd;
// 	// char	**argv;

// 	// argv = malloc(sizeof(char *) * 3);
// 	// argv[0] = ft_strdup("-rf");
// 	// argv[1] = ft_strdup("./heredoc_file");
// 	// argv[2] = NULL;
// 	// if (fork() == 0)
// 	// 	execve("/bin/rm", (char *const *)argv, NULL);
// 	// free(argv[0]);
// 	// free(argv[1]);
// 	// free(argv);
// 	fd = unlink("./heredoc_file");
// 	if (fd == -1)
// 	{
// 		perror(NULL);
// 		return (IS_ERROR);
// 	}
// 	return (0);
// }

// int	heredoc(const char *delim)
// {
// 	int		fd;
// 	char	*buf;

// 	buf = NULL;
// 	fd = open("./heredoc_file", O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	if (fd == -1)
// 	{
// 		perror(NULL);
// 		return (IS_ERROR);
// 	}
// 	write(STDOUT_FILENO, "heredoc> ", 9);
// 	while (get_next_line(STDIN_FILENO, &buf) != 0)
// 	{
// 		if (ft_strcmp(buf, delim) == 0)
// 			break ;
// 		write(STDOUT_FILENO, "heredoc> ", 9);
// 		write(fd, buf, ft_strlen(buf));
// 		write(fd, "\n", 1);
// 	}
// 	close(fd);
// 	redirect_in("./heredoc_file");
// 	if ((clear_temp()) == -1)
// 		return (IS_ERROR);
// 	return (0);
// }

// int	pipex_bonus(t_arg *arg, int *fildes, char **envp, pid_t *pid)
// {
	// if (*pid > 0)
	// {
	// 	waitpid(*pid, NULL, WNOWAIT);
	// 	if (arg->cmd2 == NULL)
	// 		return (IS_ERROR);
	// 	connect_pipe(fildes, FD_EXIT);
	// 	redirect_out(arg->outfile);
	// 	if ((execve(arg->cmd2, arg->cmd_arg2, envp)) == IS_ERROR)
	// 		perror(arg->cmd2);
	// }
	// else if (*pid == 0)
	// {
	// 	heredoc("");
	// 	if (arg->cmd1 == NULL)
	// 		return (IS_ERROR);
	// 	connect_pipe(fildes, FD_ENTRY);
	// 	if ((execve(arg->cmd1, arg->cmd_arg1, envp)) == IS_ERROR)
	// 		perror(arg->cmd1);
	// }
	// return (IS_ERROR);
// }

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
