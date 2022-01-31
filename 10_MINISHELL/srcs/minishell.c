/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 00:29:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_stream(t_mini *mini)
{
	
	return (0);
}

int	connect_redirect(t_mini *mini, char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '>')
		{
			if (argv[i][1] == '>')
			{

			}
		}
		if (argv[i][0] == '<')
		{
			if (argv[i][1] == '<')
			{
				
			}
		}
		i++;
	}
	return (0);
}

int	minishell(t_mini *mini)
{
	t_list	*head;

	head = mini->input->argv_lst;
	while (head != NULL)
	{
		if (connect_redirect(mini, ((t_argv *)(head->content))->argv) == ERROR)
			return (ERROR);
		if (ft_stream(mini) == ERROR)
			return (ERROR);
		if (ft_command(mini, head->content) == ERROR)
			return (ERROR);
		head = head->next;
	}
	return (0);
}
