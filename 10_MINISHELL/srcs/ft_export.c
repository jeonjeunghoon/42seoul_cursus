/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 01:15:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**create_export_envp(char **envp, char *env)
{
	char	**new;
	char	*envname;
	int		size;
	int		i;
	int		j;

	size = ft_two_dimension_size(envp);
	envname = get_envname_export(env);
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
	new[i] = ft_strdup(env);
	free(envname);
	return (new);
}

int	check_export_argv(char *argv)
{
	int		i;
	t_bool	is_env;
	char	*error_msg;

	i = 0;
	is_env = FALSE;
	while (argv[i])
	{
		if (argv[i] == '=')
			is_env++;
		if (is_valid_export(argv, i))
		{
			error_msg = ft_strjoin_bothside("`", argv, "'");
			error_2("export", error_msg, "not a valid identifier");
			free(error_msg);
			exit_num_set(1);
			return (ERROR);
		}
		i++;
	}
	if (is_env == FALSE)
		return (ERROR);
	return (0);
}

void	ft_export(t_mini *mini, char **argv)
{
	int		i;
	char	**new_envp;

	if (ft_two_dimension_size(argv) > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (check_export_argv(argv[i]) != ERROR)
			{
				new_envp = create_export_envp(mini->envp, argv[i]);
				ft_two_dimension_free(&(mini->envp));
				mini->envp = new_envp;
			}
			i++;
		}
	}
	else
		ft_env(mini, argv);
	exit_num_set(g_exit_state);
}
