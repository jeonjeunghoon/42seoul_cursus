/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:45:11 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/26 19:21:53 by jeunjeon         ###   ########.fr       */
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

// char	*parse_value(char **argv, int *i, int j)
// {
// 	int		size;
// 	int		position;
// 	char	*value;

// 	size = 0;
// 	position = j;
// 	while (argv[*i][position])
// 	{
// 		size++;
// 		position++;
// 	}
// 	value = malloc(sizeof(char *) * (size + 1));
// 	value[size] = '\0';
// 	size = 0;
// 	while (argv[*i][j])
// 	{
// 		value[size] = argv[*i][j];
// 		j++;
// 		size++;
// 	}
// 	return (value);
// }

// int	check_value(char *argv)
// {
// 	int		i;
// 	t_bool	valid;

// 	valid = FALSE;
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i] == '=')
// 			valid = TRUE;
// 		i++;
// 	}
// 	if (valid == FALSE)
// 		return (ERROR);
// 	return (0);
// }

// int	parse_key(char **argv, char **key, int *i)
// {
// 	int		j;

// 	j = 0;
// 	while (argv[*i][j] && argv[*i][j - 1] != '=')
// 		j++;
// 	(*key) = malloc(sizeof(char *) * (j + 1));
// 	(*key)[j] = '\0';
// 	j = 0;
// 	while (argv[*i][j] && argv[*i][j - 1] != '=')
// 	{
// 		(*key)[j] = argv[*i][j];
// 		j++;
// 	}
// 	if (argv[*i][j] == '\0')
// 	{
// 		(*i)++;
// 		return (0);
// 	}
// 	else
// 		return (j);
// 	return (ERROR);
// }

// int	check_key(char *argv)
// {
// 	int		i;
// 	char	*msg_argv;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (is_valid_export(argv, i) == ERROR)
// 		{
// 			msg_argv = ft_strjoin_bothside("`", argv, "'");
// 			error_2("export", msg_argv, "not a valid identifier");
// 			exit_num_set(1);
// 			free(msg_argv);
// 			return (ERROR);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// char	*parse_env(char **argv, int *i)
// {
// 	char	*key;
// 	char	*value;
// 	char	*env;
// 	int		j;

// 	key = NULL;
// 	value = NULL;
// 	env = NULL;
// 	j = 0;
// 	if (check_key(argv[*i]) == ERROR)
// 		return (NULL);
// 	j = parse_key(argv, &key, i);
// 	if (j == ERROR)
// 		return (NULL);
// 	// if (check_value(argv[*i]) == ERROR)
// 	// 	return (NULL);
// 	value = parse_value(argv, i, j);
// 	if (value == NULL)
// 		return (NULL);
// 	env = ft_strjoin(key, value);
// 	free(key);
// 	key = NULL;
// 	free(value);
// 	value = NULL;
// 	return (env);
// }

// void	ft_export(t_mini *mini, char **argv)
// {
// 	int		i;
// 	char	*env;
// 	char	**new_envp;

// 	if (ft_two_dimension_size(argv) > 1)
// 	{
// 		i = 1;
// 		while (argv[i])
// 		{
// 			env = parse_env(argv, &i);
// 			if (env != NULL)
// 			{
// 				new_envp = create_export_envp(mini->envp, env);
// 				ft_two_dimension_free(&(mini->envp));
// 				mini->envp = new_envp;
// 			}
// 			i++;
// 		} 
// 	}
// 	else
// 		ft_env(mini, argv);
// 	exit_num_set(g_exit_state);
// }

void	create_env(char **env, char *input, int *i, int is_quote)
{
	int	size;
	int	j;

	*env = (char *)malloc(sizeof(char) * (size + 1));
	(*env)[size] = '\0';
	j = 0;
	while (j < size)
	{
		if (is_quote == 1 && input[*i] == '\'')
		{
			(*i)++;
			continue ;
		}
		if (is_quote == 2 && input[*i] == '\"')
		{
			(*i)++;
			continue ;
		}
		(*env)[j] = input[*i];
		(*i)++;
		j++;
	}
}

int	check_value(char *input, int *i, int is_quote)
{
	while (input[*i])
	{
		if (is_quote == 0 && input[*i] == ' ')
			return (0);
		else if (is_quote == 0 && input[*i] == '\'')
			is_quote = 1;
		else if (is_quote == 0 && input[*i] == '\"')
			is_quote = 2;
		else if (is_quote == 1 && input[*i] == '\'')
			is_quote = 0;
		else if (is_quote == 2 && input[*i] == '\"')
			is_quote = 0;
		(*i)++;
	}
	return (0);
}

char	*create_export_argv(char *input, int i)
{
	char	*argv;
	int		size;
	int		position;
	int		j;

	size = 0;
	position = i;
	while (input[i] && (is_space(input[i]) == FALSE || \
		input[i] != '\'' || input[i] != '\"'))
	{
		i++;
		size++;
	}
	argv = (char *)malloc(sizeof(char) * (size + 1));
	argv[size] = '\0';
	j = 0;
	while (j < size && input[position])
	{
		argv[j] = input[position];
		j++;
		position++;
	}
	return (argv);
}

int	check_key(char *input, int *i, int is_quote)
{
	char	*argv;
	char	*msg_argv;

	msg_argv = NULL;
	if (input[*i] == '\'')
	{
		(*i)++;
		is_quote = 1;
	}
	if (input[*i] == '\"')
	{
		(*i)++;
		is_quote = 2;
	}
	if (input[*i] >= '0' && input[*i] <= '9')
	{
		argv = create_export_argv(input, *i);
		msg_argv = ft_strjoin_bothside("`", argv, "'");
		free(argv);
		error_2("export", msg_argv, "not a valid identifier");
		exit_num_set(1);
		free(msg_argv);
		return (ERROR);
	}
	while (input[*i] && input[*i] != '=')
	{
		if (is_space(input[*i]) == TRUE || \
			input[*i] == '\'' || input[*i] == '\"')
			return (ERROR);
		(*i)++;
	}
	if (input[*i] == '\0')
		return (ERROR);
	return (0);
}

int	parse_env(char *input, int *i, char **env)
{
	int	is_quote;

	is_quote = 0;
	if (check_key(input, i, is_quote) == ERROR)
		return (ERROR);
	is_quote = check_value(input, i, is_quote);
	if (is_quote == ERROR)
		return (ERROR);
	create_env(env, input, i, is_quote);
	while (input[*i] && (is_space(input[*i]) == FALSE || \
		input[*i] != '\'' || input[*i] != '\"'))
		(*i)++;
	return (0);
}

int	set_position(char *input)
{
	int	i;

	i = 6; // export 문자열 바로 뒤부터 검사 해야 하기 때문
	while (input[i] && (is_space(input[i]) == FALSE || \
		input[i] != '\'' || input[i] != '\"'))
		i++;
	return (i);
}

void	ft_export(t_mini *mini, char **argv)
{
	int		i;
	char	*env;
	char	**new_envp;

	if (ft_two_dimension_size(argv) > 1)
	{
		i = set_position(mini->input->user_input);
		while (mini->input->user_input[i])
		{
			env = NULL;
			new_envp = NULL;
			if (parse_env(mini->input->user_input, &i, &env) != ERROR)
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
