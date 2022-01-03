/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 15:54:04 by jeunjeon         ###   ########.fr       */
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

void	exit_builtin(char **argv)
{
	int	argc;

	argc = get_argc(argv);
	if (argc > 1)
	{
		error_msg("exit", "too many arguments");
		return ;
	}
	printf("exit\n");
	exit(0);
}
