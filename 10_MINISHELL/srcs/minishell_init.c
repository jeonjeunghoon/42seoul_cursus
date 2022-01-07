/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:48:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/07 14:50:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	minishell_init(t_mini **mini)
{
	char	*envp_str;

	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (ERROR);
	envp_str = getenv("PATH");
	(*mini)->envp = ft_split(envp_str, ':');
	(*mini)->minicmd_flag = FALSE;
	(*mini)->continue_flag = FALSE;
	return (0);
}
