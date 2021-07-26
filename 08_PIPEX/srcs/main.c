/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/26 18:30:11 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, const char **argv)
{
	t_arg	*arg;
	int		fd[2];
	pid_t	pid;

	if ((arg_init(argc, argv, &arg)) == -1)
		ft_exit("Error\n");
	if ((pipe(fd)) == -1)
	{
		perror(pipe);
		ft_exit(NULL);
	}
	if ((pid = fork()) == -1)
	{
		perror(NULL);
		ft_exit(NULL);
	}
	if ((pipex(arg, fd, &pid)) == -1)
	{
		perror(NULL);
		ft_exit(NULL);
	}
	return (0);
}
