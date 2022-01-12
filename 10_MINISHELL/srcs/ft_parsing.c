/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/12 17:47:54 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	token_init(t_token *token)
{
	token->argv = NULL;
	token->single_quote = FALSE;
	token->double_quote = FALSE;
	token->pipe_flag = FALSE;
	token->input = FALSE;
	token->output = FALSE;
	token->append = FALSE;
	token->heredoc = FALSE;
	token->ampersand = FALSE;
	token->vertical = FALSE;
}

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
	token->argv = (char *)malloc(sizeof(char) * (len + 1));
	token->argv[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != '\'')
	{
		token->argv[start] = input[*end];
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
	token->argv = (char *)malloc(sizeof(char) * (len + 1));
	token->argv[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != '\"')
	{
		token->argv[start] = input[*end];
		start++;
		(*end)++;
	}
	if ((start < len) || input[*end] != '\"')
		return (ERROR);
	(*end)++;
	return (0);
}

int	basic_parse(t_token *token, char *input, int *end)
{
	int	start;
	int	len;

	start = *end;
	len = 0;
	while (input[start] && input[start] != ' ' && input[start] != '\'' && input[start] != '\"')
	{
		start++;
		len++;
	}
	token->argv = (char *)malloc(sizeof(char) * (len + 1));
	token->argv[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != ' ' && input[*end] != '\'' && input[*end] != '\"')
	{
		token->argv[start] = input[*end];
		start++;
		(*end)++;
	}
	if (start < len)
		return (ERROR);
	(*end)++;
	return (0);
}

int	tokenize(t_token **token, char *input, int *start)
{
	int	end;

	(*token) = (t_token *)malloc(sizeof(t_token));
	token_init(*token);
	if (input[*start] == '\'')
	{
		(*start)++;
		(*token)->single_quote = TRUE;
		if (single_quote_parse(*token, input, start) == ERROR)
			return (ERROR);
	}
	else if (input[*start] == '\"')
	{
		(*start)++;
		(*token)->double_quote = TRUE;
		if (double_quote_parse(*token, input, start) == ERROR)
			return (ERROR);
	}
	else
		if (basic_parse(*token, input, start) == ERROR)
			return (ERROR);
	return (0);
}

int	is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || \
		ch == '\v' || ch == '\r' || ch == '\f')
		return (TRUE);
	return (FALSE);
}

void	print_lst(t_list *lst)
{
	int	i;
	
	i = 0;
	while (lst != NULL)
	{
		printf("%d: %s\n", i, ((t_token *)lst->content)->argv);
		lst = lst->next;
		i++;
	}
}

int	create_token_lst(t_list **lst, char *input)
{
	t_token *token;
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_space(input[i]) == FALSE)
		{
			if (tokenize(&token, input, &i) == ERROR)
				return (ERROR);
			ft_lstadd_back(lst, ft_lstnew(token));
			token = NULL;
		}
		else
			i++;
	}
	return (0);
}

int	exception_handling(char *input, bool sin, bool dou)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ';' || input[i] == '\\')
			return (ERROR);
		if (input[i] == '\'')
		{
			if (sin == FALSE && dou == FALSE)
				sin = TRUE;
			else if (sin == TRUE && dou == FALSE)
				sin = FALSE;
		}
		if (input[i] == '\"')
		{
			if (dou == FALSE && sin == FALSE)
				dou = TRUE;
			else if (dou == TRUE && sin == FALSE)
				dou = FALSE;
		}
		i++;
	}
	if (sin == TRUE || dou == TRUE)
		return (ERROR);
	return (0);
}

int	ft_parsing(t_mini *mini)
{
	if (exception_handling(mini->input->user_input, \
		mini->flag->single_flag, mini->flag->double_flag) == ERROR)
		return (ERROR);
	add_history(mini->input->user_input);
	if (create_token_lst(&(mini->input->token_lst), mini->input->user_input) == ERROR)
		return (ERROR);
	print_lst(mini->input->token_lst);
	// 파싱 완료 이제 다음 흐름 부터 설계해야 함
	return (0);
}
