/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 18:10:22 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_msg(char **argv, int start_ptr, int n_flag)
{
	ft_putstr_fd(argv[start_ptr], 1);
	if (argv[start_ptr + 1] != NULL)
		write(1, " ", 1);
	if (argv[start_ptr + 1] == NULL && n_flag == FALSE)
		write(1, "\n", 1);
}

int	n_option(char **argv, int *start_ptr)
{
	while (ft_strncmp(argv[*start_ptr], "-n", 3) == 0)
		(*start_ptr)++;
	if (*start_ptr == 1)
		return (FALSE);
	return (TRUE);
}

void	ft_echo(t_argv *argv)
{
	int		start_ptr;
	int		n_flag;

	n_flag = FALSE;
	if (argv->argv[1] == NULL)
		write(1, "\n", 1);
	else
	{
		start_ptr = 1;
		n_flag = n_option(argv->argv, &start_ptr);
		while (argv->argv[start_ptr] != NULL)
		{
			print_msg(argv->argv, start_ptr, n_flag);
			start_ptr++;
		}
	}
	exit_num_set(0);
}
