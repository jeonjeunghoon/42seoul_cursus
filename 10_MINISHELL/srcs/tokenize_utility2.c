/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:37:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/01 02:46:15 by jeunjeon         ###   ########.fr       */
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

void	create_new_str(t_refine *refine, int len, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen((refine->new_str)))
	{
		tmp[i] = (refine->new_str)[i];
		i++;
	}
	ft_free(&(refine->new_str));
	j = 0;
	while (i < len)
	{
		if ((refine->env)[j])
		{
			tmp[i] = (refine->env)[j];
			j++;
		}
		else
			tmp[i] = '\0';
		i++;
	}
	refine->j = i;
}

void	env_str(t_refine *refine)
{
	int		len;
	char	*tmp;

	(refine->new_str)[(refine->j)] = '\0';
	len = ft_strlen((refine->new_str)) + ft_strlen(refine->env);
	tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	create_new_str(refine, len, tmp);
	(refine->new_str) = ft_strdup(tmp);
	ft_free(&tmp);
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
