/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/02 22:44:50 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, const char **argv, char **envp)
{
	t_arg	*arg;
	int		fildes[2];
	pid_t	pid;

	if ((arg_init(argc, argv, envp, &arg)) == IS_ERROR)
		ft_exit(NULL, 1);
	if ((pipe(fildes)) == IS_ERROR)
	{
		perror("pipe");
		ft_exit(NULL, 1);
	}
	pid = fork();
	if (arg->is_heredoc == 0)
	{
		if ((pipex(arg, fildes, envp, &pid)) == IS_ERROR)
			ft_exit(NULL, 1);
	}
	else if (arg->is_heredoc == 1)
	{
		// if ((pipex_bonus(arg, fildes, envp, &pid)) == IS_ERROR)
		// 	ft_exit(NULL, 1);
	}
	return (0);
}
