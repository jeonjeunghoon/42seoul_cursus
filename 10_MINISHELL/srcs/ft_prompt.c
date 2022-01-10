/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 13:35:18 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_node **head, char ***argv, char *user_input)
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
	ft_two_dimension_free(*argv);
	*argv = NULL;
	free(user_input);
	user_input = NULL;
}

int	exception_handling_input(char *user_input, char **argv)
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
	if (argv[0] == NULL)
		return (ERROR);
	if (num_quotation % 2 != 0)
		return (ERROR);
	return (0);
}

int	parsing_input(char **prompt, char **user_input, char ***argv)
{
	*user_input = NULL;
	*user_input = readline(*prompt);
	free(*prompt);
	*prompt = NULL;
	if (*user_input == NULL)
		return (ERROR);
	*argv = ft_split(*user_input, ' ');
	return (0);
}

int	ft_prompt(t_mini *mini)
{
	char	*user_input;
	t_node	*head;
	pid_t	pid;

	user_input = NULL;
	head = NULL;
	pid = 0;
	if (load_prompt(mini) == ERROR)
		return (ERROR);
	if (parsing_input(&(mini->prompt), &user_input, &(mini->argv)) == ERROR)
		return (ERROR);
	if (exception_handling_input(user_input, mini->argv) != ERROR)
	{
		add_history(user_input);
		head = set_input(mini, mini->argv);
		ft_command(mini, head);
	}
	clear_resource(&head, &(mini->argv), user_input);
	return (0);
}
