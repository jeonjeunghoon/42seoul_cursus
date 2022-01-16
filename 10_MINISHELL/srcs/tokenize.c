/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:02:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/17 00:41:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	single_quote_parse(t_token *token, char *input, int *end)
{
	int	start;
	int	len;

	start = *end;
	len = 0;
	while (input[start] && input[start] != '\'')
	{
		start++;
		len++;
	}
	if (input[start] != '\'')
		return (ERROR);
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != '\'')
	{
		token->token[start] = input[*end];
		start++;
		(*end)++;
	}
	if ((start < len) || input[*end] != '\'')
		return (ERROR);
	(*end)++;
	return (0);
}

int	double_quote_parse(t_token *token, char *input, int *end)
{
	int	start;
	int	len;

	start = *end;
	len = 0;
	while (input[start] && input[start] != '\"')
	{
		start++;
		len++;
	}
	if (input[start] != '\"')
		return (ERROR);
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != '\"')
	{
		token->token[start] = input[*end];
		start++;
		(*end)++;
	}
	if ((start < len) || input[*end] != '\"')
		return (ERROR);
	(*end)++;
	return (0);
}

int	stream_parse(t_token *token, char *input, int *end)
{
	int	start;
	int	len;

	start = *end;
	len = 0;
	while (stream_parse_condition(input[start]) == TRUE)
	{
		start++;
		len++;
	}
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	start = 0;
	while (stream_parse_condition(input[*end]) == TRUE)
	{
		token->token[start] = input[*end];
		start++;
		(*end)++;
	}
	if (start < len)
		return (ERROR);
	return (0);
}

int	str_parse(t_token *token, char *input, int *end)
{
	int	start;
	int	len;

	start = *end;
	len = 0;
	while (str_parse_condition(input[start]) == TRUE)
	{
		start++;
		len++;
	}
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	start = 0;
	while (str_parse_condition(input[*end]) == TRUE)
	{
		token->token[start] = input[*end];
		start++;
		(*end)++;
	}
	if (start < len)
		return (ERROR);
	return (0);
}

int	tokenize(t_token *token, char *input, int *start)
{
	if (input[*start] == '\'')
	{
		(*start)++;
		token->single_quote = TRUE;
		if (single_quote_parse(token, input, start) == ERROR)
			return (ERROR);
	}
	else if (input[*start] == '\"')
	{
		(*start)++;
		token->double_quote = TRUE;
		if (double_quote_parse(token, input, start) == ERROR)
			return (ERROR);
	}
	else if (input[*start] == '|' || input[*start] == '>' || \
			input[*start] == '<' || input[*start] == '&')
	{
		if (stream_parse(token, input, start) == ERROR)
			return (ERROR);
	}
	else
		if (str_parse(token, input, start) == ERROR)
			return (ERROR);
	return (0);
}
