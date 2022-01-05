/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/05 17:17:27 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_resource(char **argv, char *user_input)
{
	free(user_input);
	user_input = NULL;
	ft_two_dimension_free(argv);
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

int	ft_prompt(t_mini *mini)
{
	char	*user_input;

	if (load_prompt(mini) == ERROR)
		return (ERROR);
	if (get_user_input(&(mini->prompt), &user_input, &(mini->argv)) == ERROR)
		return (ERROR);
	if (is_empty_input(mini->argv) == FALSE)
	{
		ft_command(mini, user_input, mini->argv);
		add_history(user_input);
	}
	clear_resource(mini->argv, user_input);
	return (0);
}
