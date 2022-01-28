/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:02:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 16:25:58 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	refine_str(t_token *token, char **envp)
{
	char	*new_str;

	new_str = replace_env(token->token, envp);
	ft_free(&(token->token));
	token->token = ft_strdup(new_str);
	ft_free(&new_str);
}

int	stream_parse(t_token *token, char *input, int *pos)
{
	int	i;
	int	len;

	len = *pos;
	while (stream_condition(input[len]) == TRUE && input[len])
		len++;
	len = len - *pos;
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	i = 0;
	while (stream_condition(input[*pos]) == TRUE && input[*pos])
	{
		token->token[i] = input[*pos];
		i++;
		(*pos)++;
	}
	if (i < len)
		return (ERROR);
	return (0);
}

int	str_parse(t_token *token, char *input, int *pos)
{
	int		i;
	int		len;

	len = *pos;
	while (str_condition(input[len], token) == TRUE && input[len])
		len++;
	len = len - *pos;
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	i = 0;
	while (str_condition(input[*pos], token) == TRUE && input[*pos])
	{
		token->token[i] = input[*pos];
		i++;
		(*pos)++;
	}
	if (i < len)
		return (ERROR);
	return (0);
}

void	tokenize(t_token *token, char *input, int *start, char **envp)
{
	if (input[*start] == '|' || input[*start] == '>' || \
			input[*start] == '<' || input[*start] == '&')
	{
		if (stream_parse(token, input, start) == ERROR)
			ft_error();
	}
	else
	{
		if (str_parse(token, input, start) == ERROR)
			ft_error();
		refine_str(token, envp);
	}
}
