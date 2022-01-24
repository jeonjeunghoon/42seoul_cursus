/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:37:12 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/24 22:39:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_envname(char *name)
{
	char	*tmp;
	char	*res;

	tmp = ft_strdup("=");
	res = ft_strjoin(name, tmp);
	free(tmp);
	return (res);
}

char	*ft_getenv(char **envp, char *name)
{
	int		i;
	char	*envname;

	envname = get_envname(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], envname, ft_strlen(envname)) == 0)
		{
			free(envname);
			return (&(envp[i][ft_strlen(envname)]));
		}
		i++;
	}
	free(envname);
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
		ft_two_dimension_free(&(argv->argv));
		free(argv);
		argv = NULL;
		free(head);
	}
}
