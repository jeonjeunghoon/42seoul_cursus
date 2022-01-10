/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 15:31:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_node **head, char **user_input)
{
	t_node	*tmp;

	tmp = NULL;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->argv != NULL)
			ft_two_dimension_free(tmp->argv);
		tmp->argv = NULL;
		free(tmp);
	}
	free(*user_input);
	*user_input = NULL;
}

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

int	parsing_input(char **prompt, char **user_input)
{
	*user_input = NULL;
	*user_input = readline(*prompt);
	free(*prompt);
	*prompt = NULL;
	if (*user_input == NULL)
		return (ERROR);
	return (0);
}

int	ft_prompt(t_mini *mini)
{
	char	*user_input;
	t_node	*head;

	user_input = NULL;
	head = NULL;
	if (parsing_input(&(mini->prompt), &user_input) == ERROR)
		return (ERROR);
	if (user_input[0] != '\0')
	{
		add_history(user_input);
		if (exception_handle_input(user_input) == ERROR)
			return (ERROR);
		// head = tokenize_input(user_input);
		// if (head == NULL)
		// 	return (ERROR);
		// ft_command(mini, head);
	}
	clear_resource(&head, &user_input);
	return (0);
}
