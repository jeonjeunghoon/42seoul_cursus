/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 00:56:17 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_msg(char **envp, char **argv, int start_ptr, int n_flag)
{
	char	*str;

	if (argv[start_ptr][0] == '$')
	{
		if (argv[start_ptr][1] == '?')
		{
			ft_putnbr_fd(g_exit_state, 1);
			if (argv[start_ptr][2] != '\0')
				ft_putstr_fd(&(argv[start_ptr][2]), 1);
		}
		else if (argv[start_ptr][2] == '\0')
			write(1, "$", 1);
		else
		{
			str = ft_getenv(envp, &(argv[start_ptr][1]));
			if (str != NULL)
				ft_putstr_fd(str, 1);
		}
	}
	else
		ft_putstr_fd(argv[start_ptr], 1);
	if (argv[start_ptr + 1] != NULL)
		write(1, " ", 1);
	else if (argv[start_ptr + 1] == NULL && n_flag == FALSE)
		write(1, "\n", 1);
}

int	n_option(char *argv, int *start_ptr)
{
	int	i;

	i = 2;
	if (ft_strncmp(argv, "-n", 2) == 0)
	{
		while (argv[i] == 'n' && argv[i])
			i++;
		if (argv[i] != '\0')
			return (FALSE);
	}
	else
		return (FALSE);
	*start_ptr = 2;
	return (TRUE);
}

int	ft_echo(t_mini *mini, char **argv)
{
	int	start_ptr;
	int	n_flag;

	n_flag = FALSE;
	if (argv[1] == NULL)
	{
		write(1, "\n", 1);
		exit_num_set(EXIT_SUCCESS);
		return (1);
	}
	start_ptr = 1;
	n_flag = n_option(argv[start_ptr], &start_ptr);
	while (argv[start_ptr] != NULL)
	{
		print_msg(mini->envp, argv, start_ptr, n_flag);
		start_ptr++;
	}
	exit_num_set(EXIT_SUCCESS);
	return (1);
}
