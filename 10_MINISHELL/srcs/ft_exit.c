/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/03 15:03:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
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
	if (argc >= 2)
	{
		if (check_argv(argv[1]) == ERROR)
		{
			error_2("exit", argv[1], "numeric argument required");
			exit_num_set(255);
		}
		else
		{
			error_1("exit", "too_many_arguments");
			exit_num_set(1);
		}
		return (ERROR);
	}
	return (0);
}

void	ft_exit(char **argv)
{
	int	argc;

	argc = 0;
	argc = ft_two_dimension_size(argv);
	if (exit_exception(argc, argv) == ERROR)
		return ;
	printf("logout\n");
	if (argc == 2 && check_argv(argv[1]) == 0)
		exit_num_set(ft_atoi(argv[1]));
	else
		exit_num_set(EXIT_SUCCESS);
	exit(g_exit_state);
}
