/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/28 16:51:52 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_bool	is_valid_symbol(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '&')
	{
		error_1(str, "invalid symbol");
		return (FALSE);
	}
	if (len == 2 && str[0] != str[1])
	{
		error_symbol(str[1]);
		return (FALSE);
	}
	if (len > 2 || (len == 2 && str[0] != str[1]))
	{
		error_symbol(str[len - 1]);
		return (FALSE);
	}
	return (TRUE);
}

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
				return (ERROR);
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
				create_argv_stream(&stream, token_lst->content, argv_lst);
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

// void	print_test(t_list *list)
// {
// 	t_list *head;
// 	t_argv *content;

// 	head = list;
// 	int i;
// 	i = 1;
// 	while (head != NULL)
// 	{
// 		printf("##### %d #####\n", i);
// 		content = head->content;
// 		for (int i = 0; content->argv[i]; i++)
// 			printf("argv[%d]=%s\n", i, content->argv[i]);
// 		head = head->next;
// 		i++;
// 		printf("#############\n");
// 	}
// }

int	ft_parsing(t_mini *mini)
{
	if (exception_handling(mini->input->user_input) == ERROR)
		return (ERROR);
	add_history(mini->input->user_input);
	create_token_lst(&(mini->input->token_lst), \
					mini->input->user_input, mini->envp);
	create_argv_lst(&(mini->input->argv_lst), mini->input->token_lst);
	// print_test(mini->input->argv_lst);
	if (check_stream_symbol(mini->input->token_lst) == ERROR)
	{
		exit_num_set(1);
		return (ERROR);
	}
	return (0);
}
