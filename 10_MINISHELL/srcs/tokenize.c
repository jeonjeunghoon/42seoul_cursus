/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:02:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/06 16:10:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	refine_init(t_refine *refine)
{
	refine->new_str = NULL;
	refine->str = NULL;
	refine->envp = NULL;
	refine->name = NULL;
	refine->env = NULL;
	refine->i = 0;
	refine->j = 0;
	refine->is_basic = TRUE;
	refine->is_single = FALSE;
	refine->is_double = FALSE;
}

int	refine_str(t_mini *mini, t_token *token, char **envp)
{
	t_refine	*refine;
	int			ret;

	ret = 0;
	refine = (t_refine *)malloc(sizeof(t_refine));
	refine_init(refine);
	refine->envp = envp;
	refine->str = token->token;
	ret = create_refined_str(mini, refine);
	ft_free(&token->token);
	if (ret != ERROR)
		token->token = ft_strdup(refine->new_str);
	ft_free(&refine->new_str);
	refine_init(refine);
	free(refine);
	refine = NULL;
	return (ret);
}

int	stream_parse(t_token *token, char *input, int *pos)
{
	int	i;
	int	len;

	len = *pos;
	while (is_stream(input[len]) == TRUE && input[len])
		len++;
	len = len - *pos;
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	i = 0;
	while (is_stream(input[*pos]) == TRUE && input[*pos])
	{
		token->token[i] = input[*pos];
		i++;
		(*pos)++;
	}
	if (i < len)
		return (ERROR);
	token->is_stream = TRUE;
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
	token->is_stream = FALSE;
	return (0);
}

t_list	*tokenize(t_mini *mini, t_token *token, char *input, int *start)
{
	t_list	*wild_str;

	wild_str = 0;
	if (input[*start] == '|' || input[*start] == '>' || \
		input[*start] == '<' || input[*start] == '&')
	{
		if (stream_parse(token, input, start) == ERROR)
		{
			ft_error("tokenize error", 1);
			exit(g_sig->exitnum);
		}
	}
	else
	{
		if (str_parse(token, input, start) == ERROR)
		{
			ft_error("tokenize error", 1);
			exit(g_sig->exitnum);
		}
		wild_str = get_wild_str(mini, token->token);
		if (!wild_str)
			if (refine_str(mini, token, mini->export_list) == ERROR)
				return ((t_list *)ERROR);
	}
	return (wild_str);
}
