/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:00:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 02:09:31 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	stream_flag_str(t_token *token)
{
	int		i;
	char	*str;

	if (token->single_quote == TRUE || token->double_quote == TRUE)
		return (0);
	i = 0;
	str = token->token;
	while (str[i] != '\0')
	{
		if (str[i] == '|' || str[i] == '>' || str[i] == '<' || str[i] == '&')
			return (TRUE);
		i++;
	}
	return (0);
}

void	token_init(t_token *token)
{
	token->token = NULL;
	token->single_quote = FALSE;
	token->double_quote = FALSE;
	token->pipe = FALSE;
	token->input = FALSE;
	token->output = FALSE;
	token->append = FALSE;
	token->heredoc = FALSE;
	token->ampersand = FALSE;
	token->vertical = FALSE;
}

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || \
		ch == '\v' || ch == '\r' || ch == '\f')
		return (TRUE);
	return (FALSE);
}

void	create_argv(t_argv **str, t_list *head, t_list **argv_lst, int size)
{
	int		i;

	(*str) = (t_argv *)malloc(sizeof(t_argv));
	(*str)->argv = (char **)malloc(sizeof(char *) * (size + 1));
	(*str)->argv[size] = NULL;
	i = 0;
	while (head != NULL && i < size && stream_flag_str(head->content) == FALSE)
	{
		(*str)->argv[i] = ft_strdup(((t_token *)head->content)->token);
		i++;
		head = head->next;
	}
	ft_lstadd_back(argv_lst, ft_lstnew(*str));
}

void	create_argv_stream(t_argv **stream, t_list *head, t_list **argv_lst)
{
	(*stream) = (t_argv *)malloc(sizeof(t_argv));
	(*stream)->argv = (char **)malloc(sizeof(char *) * 2);
	(*stream)->argv[0] = ft_strdup(((t_token *)head->content)->token);
	(*stream)->argv[1] = NULL;
	ft_lstadd_back(argv_lst, ft_lstnew(*stream));
}
