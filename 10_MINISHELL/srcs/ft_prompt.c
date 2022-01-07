/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/07 18:35:22 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(t_node **head, char ***argv, char *user_input)
{
	t_node	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->is_head == TRUE)
		{
			free(tmp);
			continue ;
		}
		free(tmp->cmd);
		if (tmp->argv != NULL)
			ft_two_dimension_free(tmp->argv);
		tmp->argv = NULL;
		tmp->cmd = NULL;
		free(tmp);
	}
	ft_two_dimension_free(*argv);
	*argv = NULL;
	free(user_input);
	user_input = NULL;
}

int	is_empty_input(char **argv)
{
	if (argv[0] != NULL)
		return (FALSE);
	return (TRUE);
}

int	get_user_input(char **prompt, char **user_input, char ***argv)
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

void	make_input_node(t_node *head, char **argv, int start, int end)
{
	t_node	*new_node;
	int		i;

	while (head->next != NULL)
		head = head->next;
	new_node = (t_node *)malloc(sizeof(t_node));
	head->next = new_node;
	new_node->cmd = ft_strdup(argv[start]);
	new_node->argv = NULL;
	i = 0;
	start++;
	if (start < end)
	{
		new_node->argv = (char **)malloc(sizeof(char *) * (end - start + 1));
		new_node->argv[end - start] = NULL;
		while (start < end)
		{
			new_node->argv[i] = ft_strdup(argv[start]);
			start++;
			i++;
		}
	}
	new_node->next = NULL;
}

int	need_split(char *argv)
{
	if (ft_strncmp(argv, "|", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, ">", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, ">>", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, "<", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, "<<", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, "||", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(argv, "&&", 3) == 0)
		return (TRUE);
	return (FALSE);
}

t_node	*set_input(t_mini *mini, char **argv)
{
	t_node	*head;
	int		start;
	int		end;

	start = 0;
	end = 0;
	head = (t_node *)malloc(sizeof(t_node));
	head->is_head = TRUE;
	head->cmd = NULL;
	head->argv = NULL;
	head->next = NULL;
	while (argv[end])
	{
		if (need_split(argv[end]) == TRUE)
		{
			make_input_node(head, argv, start, end);
			start = end + 1;
		}
		end++;
	}
	make_input_node(head, argv, start, end);
	return (head);
}

void	print_list(t_node *head)
{
	t_node *tmp;

	tmp = head;
	if (tmp->is_head == TRUE)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		printf("cmd: %s\n", tmp->cmd);
		if (tmp->argv != NULL)
		{
			for (int i = 0; tmp->argv[i]; i++)
				printf("argv: %s\n", tmp->argv[i]);
		}
		tmp = tmp->next;
	}
}

int	ft_prompt(t_mini *mini)
{
	char	*user_input;
	t_node	*head;

	if (load_prompt(mini) == ERROR)
		return (ERROR);
	if (get_user_input(&(mini->prompt), &user_input, &(mini->argv)) == ERROR)
		return (ERROR);
	if (is_empty_input(mini->argv) == FALSE)
	{
		add_history(user_input);
		head = set_input(mini, mini->argv);
		print_list(head);
		// ft_command(mini, mini->argv[0], &(mini->argv[1]));
	}
	clear_resource(&head, &(mini->argv), user_input);
	return (0);
}
