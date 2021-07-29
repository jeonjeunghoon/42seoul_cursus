/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:48:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/29 17:26:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	redirect_out(t_arg *arg)
{
	int	fd;

	unlink(arg->outfile);
	fd = open(arg->outfile, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(arg->outfile);
		ft_exit(NULL);
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
		ft_exit(NULL);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
