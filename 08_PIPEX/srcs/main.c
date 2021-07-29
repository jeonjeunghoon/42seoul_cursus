/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/29 17:49:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	is_valid_arg(int argc, const char **argv)
{
	int	i;
	int	num_of_cmd;

	num_of_cmd = 0;
	i = 2;
	while (argv[i] && (i < argc - 1))
	{
		if (num_of_cmd > 2)
			return (IS_ERROR);
		else if (argv[i][0] >= 'a' && argv[i][0] <= 'z')
		{
			num_of_cmd++;
			i++;
		}
		else if (argv[i][0] == '-')
			i++;
		else
			return (IS_ERROR);
	}
	return (0);
}

int	arg_init(int argc, const char **argv, const char **envp, t_arg **arg)
{
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (IS_ERROR);
	(*arg)->infile = ft_strdup(argv[1]);
	if (((*arg)->infile == NULL) || ((*arg)->outfile == NULL))
		return (IS_ERROR);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if ((parse_envp_path(&((*arg)->cmd_envp), envp)) == IS_ERROR)
		return (IS_ERROR);
	if (argc == 5)
	{
		if ((parse_double_quotation(argv, arg)) == IS_ERROR)
			return (IS_ERROR);
	}
	else if (argc > 5)
	{
		if ((parse_solo_quotation(argc, argv, arg)) == IS_ERROR)
			return (IS_ERROR);
	}
	else
		return (IS_ERROR);
	return (0);
}

int	pipex(t_arg *arg, int *fildes)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		if ((waitpid(pid, NULL, WNOWAIT)) == -1)
			return (IS_ERROR);
		connect_pipe(fildes, FD_EXIT);
		redirect_out(arg);
		if ((execve(arg->cmd2, arg->cmd_arg2, arg->cmd_envp)) == IS_ERROR)
			perror(arg->cmd2);
	}
	else if (pid == 0)
	{
		redirect_in(arg);
		connect_pipe(fildes, FD_ENTRY);
		if ((execve(arg->cmd1, arg->cmd_arg1, arg->cmd_envp)) == IS_ERROR)
			perror(arg->cmd1);
	}
	else
		return (IS_ERROR);
	return (0);
}

int	main(int argc, const char **argv, const char **envp)
{
	t_arg	*arg;
	int		fildes[2];

	if ((is_valid_arg(argc, argv)) == IS_ERROR)
		ft_exit("illegal arg\n");
	if ((arg_init(argc, argv, envp, &arg)) == IS_ERROR)
		ft_exit("Error\n");
	if ((pipe(fildes)) == IS_ERROR)
	{
		perror("pipe");
		ft_exit(NULL);
	}
	if ((pipex(arg, fildes)) == IS_ERROR)
	{
		perror(NULL);
		ft_exit(NULL);
	}
	return (0);
}
