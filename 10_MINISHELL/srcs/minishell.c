/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 21:05:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_bool	check_and_or(t_argv *argv)
{
	if (argv->is_and && g_sig->exitnum != 0)
		return (TRUE);
	else if (argv->is_or && g_sig->exitnum == 0)
		return (TRUE);
	return (FALSE);
}

int	minishell(t_mini *mini)
{
	t_list	*head;
	t_argv	*argv;

	head = mini->input->argv_lst;
	save_origin_fd(mini);
	while (head != NULL)
	{
		argv = head->content;
		if (argv->is_stream == FALSE)
		{
			create_argv_set(&head, argv);
			ft_command(mini, argv);
			if (head == NULL)
				break ;
			if (argv->is_and || argv->is_or)
				load_origin_fd(mini);
		}
		if (check_and_or(argv) == TRUE)
			break ;
		head = head->next;
	}
	load_origin_fd(mini);
	return (0);
}
