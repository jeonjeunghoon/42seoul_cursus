/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:48:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/01 15:24:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	redirect_out(t_arg *arg)
{
	int	fd;

	fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(arg->outfile);
		ft_exit(NULL, 1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redirect_in(t_arg *arg)
{
	int	fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd < 0)
	{
		perror(arg->infile);
		ft_exit(NULL, 1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
