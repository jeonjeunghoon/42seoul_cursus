/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:42:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 17:28:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_prompt(t_mini *mini)
{
	char	*user_input;
	int		i;

	if (prompt_init(mini) == ERROR)
		return (ERROR);
	user_input = NULL;
	user_input = readline(mini->prompt);
	if (user_input == NULL)
		return (ERROR);
	free(mini->prompt);
	mini->prompt = NULL;
	mini->splitted_input = ft_split(user_input, ' ');
	if ((ft_command(mini, user_input, mini->splitted_input)) != ENTER)
		add_history(user_input);
	free(user_input);
	ft_two_dimension_free(mini->splitted_input);
	return (0);
}
