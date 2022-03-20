/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stream_symbol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:08:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/04 15:53:01 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	stream_symbol_error(char *prev_str, char *next_str, \
							char *symbol, char *near_symbol)
{
	if (((ft_strncmp(symbol, "||", 3) == 0) || \
		(ft_strncmp(symbol, "&&", 3) == 0)) && \
		near_symbol == NULL)
		return (error_check_and_or(prev_str, next_str, symbol));
	else if ((ft_strncmp(symbol, "|", 2) == 0) && \
			near_symbol == NULL)
		return (error_check_pipe(prev_str, next_str, symbol));
	else if ((symbol[0] == '>' || symbol[0] == '<') && \
			near_symbol == NULL)
		return (error_check_redirect(next_str));
	else if (near_symbol != NULL)
		return (error_check_nearsymbol(near_symbol));
	else
		return (error_check_another(symbol));
	return (0);
}

int	check_symbol(char **symbol, char **near_symbol, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (*symbol != NULL)
		{
			*near_symbol = valid_symbol_list(str, i);
			if (*near_symbol == NULL)
				*near_symbol = ft_strdup(&(str[i]));
			break ;
		}
		*symbol = valid_symbol_list(str, i);
		if (*symbol == NULL)
		{
			error_1(*symbol, "command not found", 127);
			return (ERROR);
		}
		if ((ft_strlen(*symbol) == 2))
			i += 1;
		i++;
	}
	return (0);
}

t_bool	is_valid_symbol(t_mini *mini, char *str, char *prev_str, char *next_str)
{
	char	*symbol;
	char	*near_symbol;

	near_symbol = NULL;
	symbol = NULL;
	if (check_symbol(&symbol, &near_symbol, str) == ERROR)
		return (FALSE);
	if (stream_symbol_error(prev_str, next_str, symbol, near_symbol) == ERROR)
	{
		symbol_free(&symbol, &near_symbol);
		return (FALSE);
	}
	if (create_file(symbol, next_str) == ERROR)
	{
		symbol_free(&symbol, &near_symbol);
		return (FALSE);
	}
	if (open_file(mini, symbol, next_str) == ERROR)
	{
		symbol_free(&symbol, &near_symbol);
		return (FALSE);
	}
	symbol_free(&symbol, &near_symbol);
	return (TRUE);
}

int	check_stream_symbol(t_mini *mini, t_list *token_lst)
{
	t_list	*head;
	char	*str;
	char	*prev_str;
	char	*next_str;

	head = token_lst;
	while (head != NULL)
	{
		prev_str = NULL;
		next_str = NULL;
		str = ((t_token *)head->content)->token;
		if (is_stream(str[0]) && ((t_token *)head->content)->is_stream == TRUE)
		{
			if (head->pre != NULL)
				prev_str = ((t_token *)head->pre->content)->token;
			if (head->next != NULL)
				next_str = ((t_token *)head->next->content)->token;
			if (is_valid_symbol(mini, str, prev_str, next_str) == FALSE)
				return (ERROR);
		}
		head = head->next;
	}
	return (0);
}
