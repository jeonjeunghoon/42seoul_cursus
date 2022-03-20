/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:41:15 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 13:06:57 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_first_redirect(t_list **head, t_argv *argv, \
								t_argv *file, char ***cmd)
{
	char	**redirect_file;

	*cmd = create_cmd(argv, file);
	redirect_file = ft_strsjoin(((t_argv *)(*head)->content)->argv, \
								((t_argv *)(*head)->next->content)->argv);
	(*head) = (*head)->next->next;
	return (redirect_file);
}

void	combine_argvs(t_list **head, t_argv *argv, t_argv *file)
{
	char	**cmd;
	char	**redirect_file;
	char	**cmd_argv;
	char	**tmp;

	redirect_file = create_first_redirect(head, argv, file, &cmd);
	while (*head != NULL && ((t_argv *)(*head)->content)->is_redirect == TRUE)
	{
		tmp = ft_strsjoin(redirect_file, ((t_argv *)(*head)->content)->argv);
		ft_two_dimension_free(&redirect_file);
		redirect_file = ft_strsdup(tmp);
		ft_two_dimension_free(&tmp);
		(*head) = (*head)->next;
		cmd_argv = modify_file_argv((*head)->content);
		if (cmd_argv != NULL)
			cmd_argv_exist(&cmd, &cmd_argv, &tmp);
		tmp = ft_strsjoin(redirect_file, ((t_argv *)(*head)->content)->argv);
		ft_two_dimension_free(&redirect_file);
		redirect_file = ft_strsdup(tmp);
		ft_two_dimension_free(&tmp);
		(*head) = (*head)->next;
	}
	finish_create(argv, &cmd, &redirect_file);
}

void	is_redirect(t_list **head, t_argv *argv)
{
	combine_argvs(head, argv, (*head)->next->content);
	if (*head == NULL)
		return ;
	if (((t_argv *)(*head)->pre->content)->is_pipe == TRUE)
	{
		argv->is_pipe = TRUE;
		((t_argv *)(*head)->next->content)->was_pipe = TRUE;
	}
	else if (((t_argv *)(*head)->content)->is_and == TRUE)
		argv->is_and = TRUE;
	else if (((t_argv *)(*head)->content)->is_or == TRUE)
		argv->is_or = TRUE;
	return ;
}

t_bool	stream_check(t_list **head, t_argv *argv)
{
	if (((t_argv *)(*head)->content)->is_pipe == TRUE)
	{
		argv->is_pipe = TRUE;
		((t_argv *)(*head)->next->next->content)->was_pipe = TRUE;
		return (TRUE);
	}
	else if (((t_argv *)(*head)->content)->is_and == TRUE)
	{
		argv->is_and = TRUE;
		return (TRUE);
	}
	else if (((t_argv *)(*head)->content)->is_or == TRUE)
	{
		argv->is_or = TRUE;
		return (TRUE);
	}
	else if (((t_argv *)(*head)->content)->is_redirect == TRUE)
	{
		is_redirect(head, argv);
		return (TRUE);
	}
	return (FALSE);
}

void	create_argv_set(t_list **head, t_argv *argv)
{
	if ((*head)->next == NULL)
		return ;
	while ((*head)->next != NULL)
	{
		if (stream_check(head, argv) == TRUE)
			return ;
		*head = (*head)->next;
	}
}
