/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 02:20:44 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	basic_str(char *new_str, char *str, int *i, int *j)
{
	new_str[(*j)] = str[(*i)];
	(*i)++;
	(*j)++;
}

void	dollar_str(char **new_str, char *str, int *i, int *j, char **envp)
{
	if (str[(*i) + 1] == '\0')
	{
		(*new_str)[(*j)] = str[(*i)];
		(*i)++;
	}
	else
	{
		(*i)++;
		env_str(new_str, str, i, j, envp);
	}
}

void	double_quote_str(char **new_str, char *str, int *i, int *j, char **envp)
{
	(*i)++;
	while (str[(*i)] && str[(*i)] != '\"')
	{
		if (str[(*i)] == '$')
		{
			(*i)++;
			env_str(new_str, str, i, j, envp);
		}
		else
		{
			(*new_str)[(*j)] = str[(*i)];
			(*i)++;
			(*j)++;
		}
	}
	if (str[(*i)] == '\"')
		(*i)++;
}

void	single_quote_str(char *new_str, char *str, int *i, int *j)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		new_str[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
	if (str[*i] == '\'')
		(*i)++;
}

char	*create_refined_str(char *str, char **envp)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	new_str[ft_strlen(str)] = '\0';
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			single_quote_str(new_str, str, &i, &j);
		else if (str[i] == '\"')
			double_quote_str(&new_str, str, &i, &j, envp);
		else if (str[i] == '$')
			dollar_str(&new_str, str, &i, &j, envp);
		else
			basic_str(new_str, str, &i, &j);
	}
	return (new_str);
}
