/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 16:46:48 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_option(char *argv)
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
	return (TRUE);
}
 
int	ft_echo(t_mini *mini, char **argv)
{
	int	i;
	int	n_flag;

	mini->minicmd_flag = TRUE;
	n_flag = FALSE;
	if (argv == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	n_flag = is_option(argv[0]);
	i = 0;
	if (n_flag == TRUE)
		i = 1;
	while (argv[i] != NULL)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1] != NULL)
			write(1, " ", 1);
		if (argv[i + 1] == NULL && n_flag == FALSE)
			write(1, "\n", 1);
		else if (argv[i + 1] == NULL && n_flag == TRUE)
			write(1, "%", 1);
		i++;
	}
	return (1);
}
