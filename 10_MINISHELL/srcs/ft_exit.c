/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 13:17:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[0] == '-')
		{
			i++;
			continue ;
		}
		if (argv[i] < '0' || argv[i] > '9')
			return (ERROR);
		i++;
	}
	return (0);
}

int	exit_exception(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc > 2)
	{
		error_1("exit", "too many arguments", 1);
		return (ERROR);
	}
	else if (argc == 2)
	{
		if (check_argv(argv[1]) == ERROR)
		{
			error_2("exit", argv[1], "numeric argument required", 255);
			return (ERROR);
		}
	}
	return (0);
}

void	ft_exit(t_argv *argv)
{
	int	argc;

	exit_num_set(0);
	argc = 0;
	argc = ft_two_dimension_size(argv->argv);
	if (exit_exception(argc, argv->argv) == ERROR)
		exit(g_sig->exitnum);
	if (!(argv->is_pipe || argv->was_pipe))
		printf("logout\n");
	if (argc == 2)
		exit_num_set(ft_atoi(argv->argv[1]));
	exit(g_sig->exitnum);
}
