/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:37:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 15:42:37 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exit_num_set(int num)
{
	g_exit_state = num;
}

void	token_free(t_list *lst)
{
	t_list	*head;
	t_token	*token;

	while (lst != NULL)
	{
		head = NULL;
		token = NULL;
		head = lst;
		token = head->content;
		lst = lst->next;
		free(token->token);
		token->token = NULL;
		free(token);
		token = NULL;
		free(head);
	}
}

void	argv_free(t_list *lst)
{
	t_list	*head;
	t_argv	*argv;

	while (lst != NULL)
	{
		head = NULL;
		argv = NULL;
		head = lst;
		argv = head->content;
		lst = lst->next;
		ft_two_dimension_free(argv->argv);
		free(argv);
		argv = NULL;
		free(head);
	}
}
