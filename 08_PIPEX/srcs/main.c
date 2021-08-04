/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/04 16:48:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
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
	if ((pipex(arg, fildes, envp, &pid)) == IS_ERROR)
		ft_exit(NULL, 1);
	return (0);
}
