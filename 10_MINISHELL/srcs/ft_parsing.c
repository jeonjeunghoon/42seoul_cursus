/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/13 17:07:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_lst(t_list *lst)
{
	int	i;
	
	i = 0;
	while (lst != NULL)
	{
		printf("%d: %s\n", i, ((t_token *)lst->content)->token);
		lst = lst->next;
		i++;
	}
}

void	token_init(t_token *token)
{
	token->token = NULL;
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
	token->token = (char *)malloc(sizeof(char) * (len + 1));
	token->token[len] = '\0';
	start = 0;
	while (input[*end] && input[*end] != ' ' && input[*end] != '\'' && input[*end] != '\"')
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
	int	end;

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
	else
		if (basic_parse(token, input, start) == ERROR)
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

int	create_token_lst(t_list **lst, char *input)
{
	t_token *token;
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_space(input[i]) == FALSE)
		{
			token = (t_token *)malloc(sizeof(t_token));
			token_init(token);
			if (tokenize(token, input, &i) == ERROR)
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

int	need_split(t_token	*token)
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

void	create_argv(t_argv *argv, t_list *head, int size)
{
	int	i;

	argv->argv = (char **)malloc(sizeof(char *) * (size + 1));
	argv->argv[size] = NULL;
	i = 0;
	printf("size: %d\n", size);
	while (head != NULL && i < size && need_split(head->content) == FALSE)
	{
		argv->argv[i] = ((t_token *)head->content)->token;
		printf("argv[%d]: %s\n", i, argv->argv[i]);
		i++;
		head = head->next;
	}
}

int	create_argv_lst(t_list **argv_lst, t_list *token_lst)
{
	int		size;
	t_argv	*argv;
	t_list	*head;

	size = 0;
	argv = NULL;
	head = token_lst;
	while (token_lst != NULL)
	{
		if (need_split(token_lst->content) == TRUE || token_lst->next == NULL)
		{
			argv = (t_argv *)malloc(sizeof(t_argv));
			create_argv(argv, head, size);
			ft_lstadd_back(argv_lst, ft_lstnew(argv));
			size = 0;
			argv = NULL;
			head = token_lst->next;
		}
		if (need_split(token_lst->content) == FALSE)
			size++;
		token_lst = token_lst->next;
	}
	return (0);
}

void	print_lst2(t_list *argv)
{
	int	i;
	int	j;
	t_argv *a;

	if (argv == NULL)
		return ;
	j = 1;
	while (argv != NULL)
	{
		a = argv->content;
		i = 0;
		// printf("node\n");
		while (a->argv[i])
		{
			printf("argv[%d]: %s\n", i, a->argv[i]);
			i++;
		}
		printf("\n");
		// printf("next\n");
		argv = argv->next;
		j++;
	}
}

int	ft_parsing(t_mini *mini)
{
	if (exception_handling(mini->input->user_input, \
		mini->flag->single_flag, mini->flag->double_flag) == ERROR)
		return (ERROR);
	add_history(mini->input->user_input);
	if (create_token_lst(&(mini->input->token_lst), mini->input->user_input) == ERROR)
		return (ERROR);
	// print_lst(mini->input->token_lst);
	// 파싱 오류가 있음 리스트에 담기는 과정에서
	if (create_argv_lst(&(mini->input->argv_lst), mini->input->token_lst) == ERROR)
		return (ERROR);
	print_lst2(mini->input->argv_lst);
	return (0);
}
