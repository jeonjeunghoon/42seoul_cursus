/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:03 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/04 16:32:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
 
int		ft_echo(t_mini *mini, char **argv)
{
	int	i;
	int	n_flag;

	mini->minicmd_flag = TRUE;
	n_flag = FALSE;
	if (argv[0] == NULL)
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (argv[0][0] == '-' && argv[0][1] == 'n' && argv[0][2] == '\0')
		n_flag = TRUE;
	i = 0;
	if (n_flag == TRUE)
		i = 1;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] == NULL && n_flag == FALSE)
			write(1, "\n", 1);
		i++;
	}
	return (1);
}
