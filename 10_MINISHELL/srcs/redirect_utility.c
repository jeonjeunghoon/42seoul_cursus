/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:54:20 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 02:16:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	heredoc(char *argv, int *i)
{
	int	fd;

	if (argv[0] == '<' && argv[1] == '<' && argv[2] == '\0')
	{
		fd = open(".heredoc_tmp", O_RDONLY, 0644);
		if (fd == ERROR)
		{
			error_1(".heredoc_tmp", "No such file or directory", 1);
			return (ERROR);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		(*i)++;
	}
	return (0);
}

int	append(char *argv, char *file, int *i)
{
	int	fd;

	if (argv[0] == '>' && argv[1] == '>' && argv[2] == '\0')
	{
		fd = open(file, O_WRONLY | O_APPEND, 0644);
		if (fd == ERROR)
		{
			error_1(file, "No such file or directory", 1);
			return (ERROR);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		(*i)++;
	}
	return (0);
}

int	rtol(char *argv, char *file, int *i)
{
	int	fd;

	if (argv[0] == '<' && argv[1] == '\0')
	{
		fd = open(file, O_RDONLY, 0644);
		if (fd == ERROR)
		{
			error_1(file, "No such file or directory", 1);
			return (ERROR);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		(*i)++;
	}
	return (0);
}

int	ltor(char *argv, char *file, int *i)
{
	int	fd;

	if (argv[0] == '>' && argv[1] == '\0')
	{
		fd = open(file, O_WRONLY | O_TRUNC, 0644);
		if (fd == ERROR)
		{
			error_1(file, "No such file or directory", 1);
			return (ERROR);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		(*i)++;
	}
	return (0);
}
