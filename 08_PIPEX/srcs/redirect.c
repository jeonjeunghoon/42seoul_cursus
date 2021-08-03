/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:48:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/03 22:17:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	redirect_out(char *file_path, int is_heredoc)
{
	int	fd;

	if (is_heredoc == 1)
		fd = open(file_path, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file_path);
		ft_exit(NULL, 1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redirect_in(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(file_path);
		ft_exit(NULL, 1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
