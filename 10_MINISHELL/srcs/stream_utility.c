/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:53:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/04 17:03:33 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	heredoc_redirect(t_list *head, t_bool is_error)
{
	
}

void	r_to_l_redirect(t_list *head, char *argv, t_bool is_error)
{
	int		fd;
	char	*file_path;

	fd = 0;
	file_path = NULL;
	if (argv[1] == '<')
		heredoc_redirect(head, is_error);
	else
	{
		file_path = ((t_argv *)(head->next->content))->argv[0];
		fd = open(file_path, O_RDONLY);
		if (fd < 0)
			perror(file_path);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	append_redirect(t_list *head, t_bool is_error)
{
	
}

void	l_to_r_redirect(t_list *head, char *argv, t_bool is_error)
{
	int		fd;
	char	*file_path;

	fd = 0;
	file_path = NULL;
	if (argv[1] == '>')
		append_redirect(head, is_error);
	else
	{
		file_path = ((t_argv *)(head->next->content))->argv[0];
		fd = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			perror(file_path);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}
