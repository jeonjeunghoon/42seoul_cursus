/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:21:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 15:31:53 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	make_input_node(t_node *head, char **argv, int start, int end)
// {
// 	t_node	*new_node;
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

t_node	*set_input(t_mini *mini)
{
	t_node	*head;
	int		start;
	int		end;

	start = 0;
	end = 0;
	head = (t_node *)malloc(sizeof(t_node));
	head->is_head = TRUE;
	head->argv = NULL;
	head->next = NULL;
	// while (argv[end])
	// {
	// 	if (need_split(argv[end]) == TRUE)
	// 	{
	// 		make_input_node(head, argv, start, end);
	// 		start = end + 1;
	// 	}
	// 	end++;
	// }
	// make_input_node(head, argv, start, end);
	return (head);
}
