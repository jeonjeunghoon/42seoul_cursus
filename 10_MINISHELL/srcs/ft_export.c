/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/26 22:32:52 by jeunjeon         ###   ########.fr       */
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

char	*parse_value(char **argv, int *i, int j)
{
	int		size;
	int		position;
	char	*value;

	size = 0;
	position = j;
	while (argv[*i][position])
	{
		size++;
		position++;
	}
	value = malloc(sizeof(char *) * (size + 1));
	value[size] = '\0';
	size = 0;
	while (argv[*i][j])
	{
		value[size] = argv[*i][j];
		j++;
		size++;
	}
	return (value);
}

int	check_value(char *argv)
{
	int		i;
	t_bool	valid;

	valid = FALSE;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '=')
			valid = TRUE;
		i++;
	}
	if (valid == FALSE)
		return (ERROR);
	return (0);
}

int	parse_key(char **argv, char **key, int *i)
{
	int		j;

	j = 0;
	while (argv[*i][j] && argv[*i][j - 1] != '=')
		j++;
	(*key) = malloc(sizeof(char *) * (j + 1));
	(*key)[j] = '\0';
	j = 0;
	while (argv[*i][j] && argv[*i][j - 1] != '=')
	{
		(*key)[j] = argv[*i][j];
		j++;
	}
	if (argv[*i][j] == '\0')
	{
		(*i)++;
		return (0);
	}
	else
		return (j);
	return (ERROR);
}

int	check_key(char *argv)
{
	int		i;
	char	*msg_argv;

	i = 0;
	while (argv[i])
	{
		if (is_valid_export(argv, i) == ERROR)
		{
			msg_argv = ft_strjoin_bothside("`", argv, "'");
			error_2("export", msg_argv, "not a valid identifier");
			exit_num_set(1);
			free(msg_argv);
			return (ERROR);
		}
		i++;
	}
	return (0);
}

char	*parse_env(char **argv, int *i)
{
	char	*key;
	char	*value;
	char	*env;
	int		j;

	key = NULL;
	value = NULL;
	env = NULL;
	j = 0;
	if (check_key(argv[*i]) == ERROR)
		return (NULL);
	j = parse_key(argv, &key, i);
	if (j == ERROR)
		return (NULL);
	value = parse_value(argv, i, j);
	if (value == NULL)
		return (NULL);
	env = ft_strjoin(key, value);
	free(key);
	key = NULL;
	free(value);
	value = NULL;
	return (env);
}

void	ft_export(t_mini *mini, char **argv)
{
	int		i;
	char	*env;
	char	**new_envp;

	if (ft_two_dimension_size(argv) > 1)
	{
		i = 1;
		while (argv[i])
		{
			env = parse_env(argv, &i);
			if (env != NULL)
			{
				new_envp = create_export_envp(mini->envp, env);
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
