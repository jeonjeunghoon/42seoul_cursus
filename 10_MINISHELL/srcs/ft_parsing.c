/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 16:55:51 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_stream_symbol(t_list *token_lst)
{
	t_list	*head;
	char	*str;

	head = token_lst;
	while (head != NULL)
	{
		str = ((t_token *)head->content)->token;
		if (str[0] == '|' || str[0] == '>' || str[0] == '<' || str[0] == '&')
		{
			if (is_valid_symbol(str) == FALSE)
			{
				exit_num_set(1);
				return (ERROR);
			}
		}
		head = head->next;
	}
	return (0);
}

void	create_argv_lst(t_list **argv_lst, t_list *token_lst)
{
	int		size;
	t_argv	*str;
	t_argv	*stream;
	t_list	*head;

	argv_lst_init(&str, &stream, &size);
	head = token_lst;
	while (token_lst != NULL)
	{
		if (stream_flag_str(token_lst->content) == FALSE)
			size++;
		if (stream_flag_str(token_lst->content) == TRUE || \
							token_lst->next == NULL)
		{
			if (size != 0)
				create_argv(&str, head, argv_lst, size);
			if (stream_flag_str(token_lst->content) == TRUE)
				create_stream(&stream, token_lst->content, argv_lst);
			argv_lst_init(&str, &stream, &size);
			head = token_lst->next;
		}
		token_lst = token_lst->next;
	}
}

void	create_token_lst(t_list **lst, char *input, char **envp)
{
	t_token	*token;
	int		i;

	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]) == FALSE)
		{
			token = (t_token *)malloc(sizeof(t_token));
			token_init(token);
			tokenize(token, input, &i, envp);
			ft_lstadd_back(lst, ft_lstnew(token));
			token = NULL;
		}
		else
			i++;
	}
}

int	exception_handling(char *input)
{
	int		i;
	t_bool	sin;
	t_bool	dou;

	sin = FALSE;
	dou = FALSE;
	i = 0;
	while (input[i])
	{
		if (input[i] == ';' || input[i] == '\\')
			return (ERROR);
		if (input[i] == '\'' || input[i] == '\"')
			exception_utility(input[i], &sin, &dou);
		i++;
	}
	if (sin == TRUE || dou == TRUE)
		return (ERROR);
	return (0);
}

int	ft_parsing(t_mini *mini)
{
	if (exception_handling(mini->input->user_input) == ERROR)
		return (ERROR);
	add_history(mini->input->user_input);
	create_token_lst(&(mini->input->token_lst), \
					mini->input->user_input, mini->envp);
	create_argv_lst(&(mini->input->argv_lst), mini->input->token_lst);
	if (check_stream_symbol(mini->input->token_lst) == ERROR)
		return (ERROR);
	return (0);
}
