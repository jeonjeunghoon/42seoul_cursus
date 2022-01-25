/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 16:43:39 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_export_envp(char **envp, char *argv)
{
	char	**new;
	char	*envname;
	int		size;
	int		i;
	int		j;

	size = ft_two_dimension_size(envp);
	envname = get_envname_export(argv);
	if (ft_getenv(envp, envname) == NULL)
		size++;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	i = 0;
	j = 0;
	while (i < size && envp[j])
	{
		if (ft_strncmp(envp[j], envname, ft_strlen(envname)) == 0)
			j++;
		if (envp[j] != NULL)
			new[i++] = ft_strdup(envp[j++]);
	}
	new[i] = ft_strdup(argv);
	free(envname);
	return (new);
}

char	*get_env(t_mini *mini, char **argv, int *i, int check)
{
	t_list	*head;
	char	*env;
	int		j;

	head = mini->input->token_lst->next;
	j = 0;
	while (head != NULL && j < *i)
	{
		head = head->next;
		j++;
	}
	if (argv[*i][check - 1] == '=' && argv[*i][check] == '\0' && \
		argv[(*i) + 1] != NULL && \
		((t_token *)head->content)->double_quote == TRUE || \
		((t_token *)head->content)->single_quote == TRUE)
	{
		env = ft_strjoin(argv[*i], ((t_token *)(head)->content)->token);
		(*i)++;
		return (env);
	}
	env = ft_strdup(argv[*i]);
	return (env);
}

int	check_export_argv(char *argv)
{
	int		i;
	int		is_env;
	char	*msg_argv;

	i = 0;
	is_env = 0;
	while (argv[i])
	{
		if (argv[i] == '=')
			is_env++;
		if (is_wrong_export(argv, i))
		{
			msg_argv = ft_strjoin_bothside("'", argv, "'");
			error_2("export", msg_argv, "not a valid identifier");
			exit_num_set(1);
			free(msg_argv);
			return (ERROR);
		}
		i++;
	}
	if (is_env != 1)
		return (ERROR);
	return (i);
}

void	ft_export(t_mini *mini, char **argv)
{
	int		i;
	int		check;
	char	*env;
	char	**new_envp;

	if (ft_two_dimension_size(argv) > 1)
	{
		i = 0;
		while (argv[++i])
		{
			check = check_export_argv(argv[i]);
			if (check != ERROR)
			{
				env = get_env(mini, argv, &i, check);
				new_envp = create_export_envp(mini->envp, env);
				free(env);
				ft_two_dimension_free(&(mini->envp));
				mini->envp = new_envp;
			}
		}
	}
	else
		ft_env(mini, argv);
	exit_num_set(g_exit_state);
}
