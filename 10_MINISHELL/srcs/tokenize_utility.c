/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:51:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/27 18:51:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// char	*valid_env(char **chunk, char *p, char *env)
// {
// 	char	*new_chunk;

// 	new_chunk = NULL;
// 	*p = '\0';
// 	new_chunk = ft_strjoin(*chunk, env);
// 	*p = '$';
// 	ft_free(chunk);
// 	*chunk = ft_strdup(new_chunk);
// 	ft_free(&new_chunk);
// 	return (*chunk);
// }

// char	**invalid_env(char **chunk, char *p)
// {
// 	char	*new_chunk;
// 	int		len;
// 	int		i;

// 	new_chunk = NULL;
// 	len = 0;
// 	while (chunk[len] && chunk[len] != *p)
// 		len++;
// 	new_chunk = (char *)malloc(sizeof(char) * (len + 1));
// 	new_chunk[len] = '\0';
// 	i = 0;
// 	while (chunk[len])
// 	{
		
// 	}
// }

// void	remove_env(char **chunk, char **envp)
// {
// 	int		i;
// 	char	*p;
// 	char	*env;
// 	char	*new_chunk;

// 	p = NULL;
// 	env = NULL;
// 	new_chunk = NULL;
// 	i = 0;
// 	while (chunk[i])
// 	{
// 		p = ft_strchr(chunk[i], '$');
// 		while (p != NULL)
// 		{
// 			env = ft_getenv(envp, p + 1);
// 			if (env == NULL)
// 				chunk[i] = invalid_env(&(chunk[i]), p);
// 			else
// 				chunk[i] = valid_env(&(chunk[i]), p, env);
// 			printf("new_chunk: %s\n", *chunk);
// 			p = NULL;
// 			p = ft_strchr(chunk[i], '$');
// 		}
// 		i++;
// 	}
// }

char	*remove_double_quote(char *str, char **envp)
{
	char	**chunk;
	char	*new_str;
	char	*tmp_str;
	int		i;

	chunk = ft_split(str, '\"');
	remove_env(chunk, envp);			// 알고리즘 수정 필요
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
