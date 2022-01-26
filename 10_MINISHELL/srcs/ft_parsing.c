/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/26 15:04:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_stream_symbol(t_list *token_lst)
{
	t_list	*head;
	t_token	*token;

	head = token_lst;
	while (head != NULL)
	{
		token = head->content;
		if (token->pipe || token->output || token->append || \
			token->input || token->heredoc || token->ampersand || \
			token->vertical || token->vertical)
		{
			
		}
		head = head->next;
	}
}

int	create_argv_lst(t_list **argv_lst, t_list *token_lst)
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
	return (0);
}

int	create_token_lst(t_list **lst, char *input)
{
	t_token	*token;
	int		i;

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

int	exception_handling(char *input, t_bool sin, t_bool dou)
{
	int		i;

	i = -1;
	while (input[++i])
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
	if (exception_handling(mini->input->user_input, \
		mini->flag->single_flag, mini->flag->double_flag) == ERROR)
		return (ERROR);
	add_history(mini->input->user_input);
	if (create_token_lst(&(mini->input->token_lst), \
						mini->input->user_input) == ERROR)
		return (ERROR);
	if (create_argv_lst(&(mini->input->argv_lst), \
						mini->input->token_lst) == ERROR)
		return (ERROR);

	// print_test(mini->input->argv_lst);

	if (check_stream_symbol(mini->input->token_lst) == ERROR)
		return (ERROR);
	return (0);
}
