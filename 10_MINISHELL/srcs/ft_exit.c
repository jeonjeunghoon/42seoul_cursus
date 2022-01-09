/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/09 17:55:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] > '0' || argv[i] < '9')
			return (ERROR);
		i++;
	}
	return (0);
}

void	ft_exit(t_mini *mini, char **argv)
{
	int	argc;

	argc = 0;
	mini->minicmd_flag = TRUE;
	argc = ft_two_dimension_size(argv);
	if (argc > 2)
	{
		too_many_arguments("exit");
		return ;
	}
	if (argc == 2 && check_argv(argv[1]) == 0)
		g_exit_state = ft_atoi(argv[1]);
	printf("logout\n");
	exit(EXIT_SUCCESS);
}
