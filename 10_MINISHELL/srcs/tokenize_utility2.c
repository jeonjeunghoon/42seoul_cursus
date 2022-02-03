/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:37:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 22:15:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_envname_parse(char *str, int *i)
{
	char	*name;
	int		len;
	int		j;

	len = (*i);
	while (str[len] && str[len] != '$' && \
			str[len] != '\"' && str[len] != '\'')
		len++;
	len = len - (*i);
	name = (char *)malloc(sizeof(char) * (len + 1));
	name[len] = '\0';
	j = 0;
	while (j < len && str[*i] && str[*i] != '$' && \
			str[*i] != '\"' && str[len] != '\'')
	{
		name[j] = str[*i];
		(*i)++;
		j++;
	}
	return (name);
}

void	create_new_str(t_refine *refine, int tmp_len, char *tmp)
{
	int	i;
	int	j;
	int	new_len;

	i = 0;
	new_len = ft_strlen(refine->new_str);
	while (i < new_len)
	{
		tmp[i] = refine->new_str[i];
		i++;
	}
	j = 0;
	while (i < tmp_len && refine->env[j])
	{
		tmp[i] = refine->env[j];
		i++;
		j++;
	}
	refine->j = i;
}

void	env_str(t_refine *refine)
{
	int		len;
	char	*tmp;

	refine->new_str[refine->j] = '\0';
	len = ft_strlen(refine->new_str) + ft_strlen(refine->env);
	tmp = malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	create_new_str(refine, len, tmp);
	ft_free(&refine->new_str);
	refine->new_str = ft_strdup(tmp);
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
