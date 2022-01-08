/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 17:26:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

	mini->minicmd_flag = TRUE;
	n_flag = FALSE;
	if (argv[1] == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	start_ptr = 1;
	n_flag = n_option(argv[start_ptr], &start_ptr);
	while (argv[start_ptr] != NULL)
	{
		write(1, argv[start_ptr], ft_strlen(argv[start_ptr]));
		if (argv[start_ptr + 1] != NULL)
			write(1, " ", 1);
		else if (argv[start_ptr + 1] == NULL && n_flag == FALSE)
			write(1, "\n", 1);
		else if (argv[start_ptr + 1] == NULL && n_flag == TRUE)
			write(1, "%", 1);
		start_ptr++;
	}
	return (1);
}
