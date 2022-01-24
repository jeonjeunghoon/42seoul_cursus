/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 00:25:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_envname_export(char *argv)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	while (argv[size] && argv[size] != '=')
		size++;
	if (argv[size] != '=')
		return (NULL);
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	i = 0;
	while (i < size && argv[i])
	{
		res[i] = argv[i];
		i++;
	}
	return (res);
}

char	**create_export_envp(char **envp, char *argv, int size)
{
	char	**new;
	char	*envname;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	envname = get_envname_export(argv);
	i = 0;
	j = 0;
	while (i < size && envp[j])
	{
		if (ft_strncmp(envp[j], envname, ft_strlen(envname)) == 0)
			j++;
		if (envp[j] != NULL)
		{
			new[i] = ft_strdup(envp[j]);
			i++;
			j++;
		}
	}
	new[i] = ft_strdup(argv);
	free(envname);
	return (new);
}

int	is_wrong_export(char *argv, int i)
{
	if ((argv[i] != '_' && argv[0] == '=' \
		&& !(argv[i] >= 'a' && argv[i] <= 'z') \
		&& !(argv[i] >= 'A' && argv[i] <= 'Z') \
		&& !(argv[i] >= '0' && argv[i] <= '9')) \
		|| (argv[0] >= '0' && argv[0] <= '9'))
		return (TRUE);
	return (FALSE);
}

int	check_export_argv(char *argv, int *exit_num)
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
			error_msg("export", msg_argv, "not a valid identifier");
			free(msg_argv);
			*exit_num = 1;
			return (ERROR);
		}
		i++;
	}
	if (is_env != 1)
		return (ERROR);
	return (0);
}

void	ft_export(t_mini *mini, char **argv)
{
	int		exit_num;
	int		i;
	int		size;
	char	**new_envp;

	mini->flag->minicmd_flag = TRUE;
	exit_num = 0;
	if (ft_two_dimension_size(argv) > 1)
	{
		i = 1;
		while (argv[i])
		{
			if (check_export_argv(argv[i], &exit_num) != ERROR)
			{
				size = ft_two_dimension_size(mini->envp) + 1;
				new_envp = create_export_envp(mini->envp, argv[i], size);
				ft_two_dimension_free(&(mini->envp));
				mini->envp = new_envp;
			}
			i++;
		}
	}
	else
		ft_env(mini, argv);
	exit_num_set(exit_num);
}
