/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:02:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 00:59:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_stream(t_mini *mini)
{
	
	return (0);
}

int	minishell(t_mini *mini)
{
	t_list	*head;

	head = mini->input->argv_lst;
	while (head != NULL)
	{
		// connect_redirect();
		if (ft_stream(mini) == ERROR)
			return (ERROR);
		if (ft_command(mini, head->content) == ERROR)
			return (ERROR);
		head = head->next;
	}
}
