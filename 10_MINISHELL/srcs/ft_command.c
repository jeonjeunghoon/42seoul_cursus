/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 14:04:29 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

void	execute_command(t_mini *mini)
{

}

int	check_command(t_mini *mini)
{
	
	return (0);
}

int	ft_command(t_mini *mini, char *user_input)
{
	if (user_input[0] == '\0')
		return (ENTER);
	if (check_command(mini) == ERROR)
		printf("bash: %s: command not found\n", user_input);
	else
		execute_command(mini);
	return (0);
}
