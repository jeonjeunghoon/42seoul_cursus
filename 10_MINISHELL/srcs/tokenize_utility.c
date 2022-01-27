/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 01:06:48 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*remove_double_quote(char *str, char **envp)
{
	char	**chunk;
	char	*new_str;
	char	*tmp_str;
	int		i;

	chunk = ft_split(str, '\"');
	if (chunk)
	new_str = ft_strdup(chunk[0]);
	tmp_str = NULL;
	i = 0;
	if (ft_two_dimension_size(chunk) > 1)
	{
		i = 1;
		while (chunk[i])
		{
			tmp_str = ft_strjoin(new_str, chunk[i]);
			ft_free(&new_str);
			new_str = ft_strdup(tmp_str);
			ft_free(&tmp_str);
			i++;
		}
	}
	ft_two_dimension_free(&chunk);
	return (new_str);
}

char	*remove_single_quote(char *str)
{
	char	**chunk;
	char	*new_str;
	char	*tmp_str;
	int		i;

	chunk = ft_split(str, '\'');
	new_str = ft_strdup(chunk[0]);
	tmp_str = NULL;
	i = 0;
	if (ft_two_dimension_size(chunk) > 1)
	{
		i = 1;
		while (chunk[i])
		{
			tmp_str = ft_strjoin(new_str, chunk[i]);
			ft_free(&new_str);
			new_str = ft_strdup(tmp_str);
			ft_free(&tmp_str);
			i++;
		}
	}
	ft_two_dimension_free(&chunk);
	return (new_str);
}

char	*get_envname_parse(char *str, int *i)
{
	char	*name;
	int		len;
	int		j;

	len = (*i);
	while (str[len] && str[len] != '$' && str[len] != '\"')
		len++;
	len = len - (*i);
	name = (char *)malloc(sizeof(char) * (len + 1));
	name[len] = '\0';
	j = 0;
	while (j < len && str[*i] && str[*i] != '$' && str[*i] != '\"')
	{
		name[j] = str[*i];
		(*i)++;
		j++;
	}
	return (name);
}

char	*replace_env(char *str, char **envp)
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
		{
			i++;
			while (str[i] && str[i] != '\'')
			{
				new_str[j] = str[i];
				i++;
				j++;
			}
			if (str[i] == '\'')
				i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
			{
				if (str[i] == '$')
				{
					i++;
					char *name = get_envname_parse(str, &i);
					char *env = ft_getenv(envp, name);
					ft_free(&name);
					if (env == NULL)
						continue ;
					new_str[j] = '\0';
					int	len;
					len = ft_strlen(new_str) + ft_strlen(env);
					char *tmp = malloc(sizeof(char) * (len + 1));
					tmp[len] = '\0';
					int k = 0;
					while (k < ft_strlen(new_str))
					{
						tmp[k] = new_str[k];
						k++;
					}
					ft_free(&new_str);
					int a = 0;
					while (k < len)
					{
						if (env[a])
						{
							tmp[k] = env[a];
							k++;
							a++;
						}
						else
						{
							tmp[k] = '\0';
							k++;
						}
					}
					new_str = ft_strdup(tmp);
					ft_free(&tmp);
					j = k;
				}
				else
				{
					new_str[j] = str[i];
					i++;
					j++;
				}
			}
			if (str[i] == '\"')
				i++;
		}
		else if (str[i] == '$')
		{
			if (str[i + 1] == '\0')
			{
				new_str[j] = str[i];
				i++;
			}
			else
			{
				i++;
				char *name = get_envname_parse(str, &i);
				char *env = ft_getenv(envp, name);
				ft_free(&name);
				if (env == NULL)
					continue ;
				new_str[j] = '\0';
				int	len;
				len = ft_strlen(new_str) + ft_strlen(env);
				char *tmp = malloc(sizeof(char) * (len + 1));
				tmp[len] = '\0';
				int k = 0;
				while (k < ft_strlen(new_str))
				{
					tmp[k] = new_str[k];
					k++;
				}
				ft_free(&new_str);
				int a = 0;
				while (k < len)
				{
					if (env[a])
					{
						tmp[k] = env[a];
						k++;
						a++;
					}
					else
					{
						tmp[k] = '\0';
						k++;
					}
				}
				new_str = ft_strdup(tmp);
				ft_free(&tmp);
				j = k;
			}
		}
		else
		{
			new_str[j] = str[i];
			i++;
			j++;
		}
	}
	return (new_str);
}
