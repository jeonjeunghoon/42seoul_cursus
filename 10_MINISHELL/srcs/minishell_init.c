/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:48:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 13:13:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	minishell_init(t_mini **mini)
{
	char	*envp_str;

	*mini = (t_mini *)malloc(sizeof(t_mini));
	if (*mini == NULL)
		return (ERROR);
	(*mini)->locate = NULL;
	(*mini)->prompt = NULL;
	(*mini)->path_of_cmd = NULL;
	(*mini)->argv = NULL;
 	(*mini)->envp = NULL;
	envp_str = getenv("PATH");
	(*mini)->envp = ft_split(envp_str, ':');
	(*mini)->minicmd_flag = FALSE;
	(*mini)->continue_flag = FALSE;
	return (0);
}
