/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:48:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/26 14:13:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	redirect_out(t_arg *arg)
{
	int	fd;

	fd = open(arg->outfile, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(arg->outfile);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_in(t_arg *arg)
{
	int	fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd < 0)
	{
		perror(arg->infile);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
