/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 18:30:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	get_argc(char **argv)
{
	int		argc;

	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	return (argc);
}

void	ft_exit(t_mini *mini, char **argv)
{
	int	argc;

	mini->minicmd_flag = TRUE;
	argc = get_argc(argv);
	if (argc > 1)
	{
		too_many_arguments(argv[0]);
		return ;
	}
	printf("exit\n");
	exit(0);
}
