/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 17:10:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	is_exit(t_mini *mini)
{
	if (mini->exit_flag == 0)
		return ;
	exit(0);
}

int	main(int argc, const char **argv)
{
	t_mini	*mini;

	if ((minishell_init(&mini)) == ERROR)
		error_func(mini);
	while (TRUE)
	{
		if ((ft_prompt(mini)) == ERROR)
			error_func(mini);
		is_exit(mini);
	}
	return (0);
}
