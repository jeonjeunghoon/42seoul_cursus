/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/10/15 15:39:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_resource(t_mini *mini)
{
	
}

int	execute_command(t_mini *mini)
{
	return (0);	
}

int	check_pipex(t_mini *mini)
{
	return (0);
}

int	check_command(t_mini *mini)
{
	return (0);
}

int	new_prompt(t_mini *mini)
{
	mini->line = readline("prompt: ");
	if (mini->line)
		printf("%s\n", mini->line);
	else
		return (0);
	add_history(mini->line);
	return (0);
}

void	loop_init(t_mini *mini)
{
	return ;
}

int	minishell_init(t_mini **mini)
{
	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (1);
	(*mini)->line = NULL;
	(*mini)->is_finish = 0;
	return (0);
}

int	main(int argc, const char **argv)
{
	t_mini	*mini;

	if ((minishell_init(&mini)) == 1)
		exit(1);
	while (mini->is_finish != 1)
	{
		loop_init(mini);
		new_prompt(mini);
		if ((check_command(mini)) == 1)
			continue ;
		mini->is_finish = execute_command(mini);
	}
	free_resource(mini);
	return (0);
}
