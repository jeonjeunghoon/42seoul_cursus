/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:37:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/20 18:56:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char		*ft_getenv(char **envp, char *name)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("=");
	tmp2 = ft_strjoin(name, tmp);
	free(tmp);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], tmp2, ft_strlen(tmp2)) == 0)
			return (name);
		i++;
	}
	free(tmp2);
	return (NULL);
}

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
