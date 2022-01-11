/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/11 17:06:35 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	append_lst(t_list *token_lst, t_token *token)
{
	/* 리스트 연결 */
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = NULL;
	lst->next = NULL;
	if (token_lst == NULL)
		token_lst = lst;
	else
	{
		while (token_lst->next != NULL)
			token_lst = token_lst->next;
		token_lst->next = lst;
	}
	lst->content = token;
}

void	token_init(t_token *token)
{
	token->argv = FALSE;
	token->double_quote = FALSE;
	token->pipe_flag = FALSE;
	token->input = FALSE;
	token->output = FALSE;
	token->append = FALSE;
	token->heredoc = FALSE;
	token->ampersand = FALSE;
	token->vertical = FALSE;
}

int	tokenize(t_token **token, char *user_input, int *start)
{
	/* 토크나이징 */
	int	end;

	token = (t_token *)malloc(sizeof(t_token));
	token_init(token);
	/* 여기부터 구현하면 됨 */
	if (user_input[i] == '\'')
	{
		if (single_quote_parse(*token, user_input, i + 1) == ERROR) // 닫히지 않은 '
			return (ERROR);
	}
	else if (user_input[i] == '\"')
	{
		if (double_quote_parse(*token, user_input, i + 1) == ERROR) // 닫히지 않은 "
			return (ERROR);
	}
	else
		basic_parse(*token, user_input, i);
	return (0);
}

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || \
		ch == '\v' || ch == '\r' || ch == '\f')
		return (TRUE);
	return (FALSE);
}

int	create_token_lst(t_list *token_lst, char *user_input)
{
	t_token *token;
	int	i;

	i = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\\' || user_input[i] == ';')
			return (ERROR); 
		if (is_space(user_input[i]) == FALSE)
		{
			if (tokenize(&token, user_input, &i) == ERROR)
				return (ERROR);
			append_lst(token_lst, token);
			token = NULL;
		}
		i++;
	}
}

int	ft_parsing(t_mini *mini)
{
	add_history(mini->input->user_input);
	if (create_token_lst(mini->input->token_lst, mini->input->user_input) == ERROR)
		return (ERROR);
	return (0);
}
