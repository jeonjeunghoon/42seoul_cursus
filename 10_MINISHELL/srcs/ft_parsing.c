/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:39:07 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 17:02:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	make_input_token(t_token *head, char **argv, int start, int end)
// {
// 	t_token	*new_token;
// 	int		i;

// 	while (head->next != NULL)
// 		head = head->next;
// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	head->next = new_node;
// 	new_node->argv = NULL;
// 	i = 0;
// 	if (start < end)
// 	{
// 		new_node->argv = (char **)malloc(sizeof(char *) * (end - start + 1));
// 		new_node->argv[end - start] = NULL;
// 		while (start < end)
// 		{
// 			new_node->argv[i] = ft_strdup(argv[start]);
// 			start++;
// 			i++;
// 		}
// 	}
// 	new_node->next = NULL;
// }

// int	need_split(char *argv)
// {
// 	if (ft_strncmp(argv, "|", 2) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, ">", 2) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, ">>", 3) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, "<", 2) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, "<<", 3) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, "||", 3) == 0)
// 		return (TRUE);
// 	else if (ft_strncmp(argv, "&&", 3) == 0)
// 		return (TRUE);
// 	return (FALSE);
// }

// int	token_init(t_token **token)
// {
// 	*token = NULL
// 	*token = (t_token *)malloc(sizeof(t_token));
// 	(*token == NULL)
// 		return (ERROR);
// 	(*token)->argv = NULL;
// 	(*token)->next = NULL;
// }

// t_token	*tokenize_input(char *user_input)
// {
// 	t_token	*head;
// 	int		i;

// 	head = NULL;
// 	head = (t_token *)malloc(sizeof(t_token));
// 	head->is_head = TRUE;
// 	head->argv = NULL;
// 	head->next = NULL;
// 	i = 0;
// 	while (user_input[])
// 	{
// 		while (is_space() == TRUE)
// 			i++;
		
// 	}
// 	make_input_token(head, argv, start, end);
// 	return (head);
// }




int	exception_handle_input(char *user_input)
{
	int	i;
	int	num_quotation;

	num_quotation = 0;
	i = 0;
	while (user_input[i])
	{
		if (user_input[i] == ';' || user_input[i] == '\\')
			return (ERROR);
		if (user_input[i] == '\'' || user_input[i] == '\"')
			num_quotation++;
		i++;
	}
	if (num_quotation % 2 != 0)
		return (ERROR);
	return (0);
}

int	ft_parsing(t_mini *mini)
{
	if (exception_handle_input(mini->input->user_input) == ERROR)
		return (ERROR);
	// 여기 까지 문제 없음 파싱부터 하면 됨
	// tokenize_input(mini);
	return (0);
}
