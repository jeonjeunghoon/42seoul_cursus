/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:37:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 02:21:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	env_str(char **new_str, char *str, int *i, int *j, char **envp)
{
	char *name = get_envname_parse(str, i);
	char *env = ft_getenv(envp, name);

	ft_free(&name);
	if (env == NULL)
		return ;
	(*new_str)[(*j)] = '\0';
	int	len;
	len = ft_strlen((*new_str)) + ft_strlen(env);
	char *tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	int k = 0;
	while (k < ft_strlen((*new_str)))
	{
		tmp[k] = (*new_str)[k];
		k++;
	}
	ft_free(new_str);
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
	(*new_str) = ft_strdup(tmp);
	ft_free(&tmp);
	*j = k;
}

t_bool	stream_condition(char c)
{
	if (c != '|' && c != '>' && c != '<' && c != '&')
		return (FALSE);
	return (TRUE);
}

t_bool	str_condition(char c, t_token *token)
{
	if (c == '|' || c == '>' || c == '<' || c == '&')
		return (FALSE);
	exception_utility(c, &(token->single_quote), &(token->double_quote));
	if (token->single_quote == FALSE && token->double_quote == FALSE && \
		c == ' ')
		return (FALSE);
	return (TRUE);
}
