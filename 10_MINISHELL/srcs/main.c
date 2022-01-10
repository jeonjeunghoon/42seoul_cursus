/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:49:06 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 15:26:33 by jeunjeon         ###   ########.fr       */
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
 	(*mini)->envp = NULL;
	envp_str = getenv("PATH");
	if (envp_str == NULL)
		return (ERROR);
	(*mini)->envp = ft_split(envp_str, ':');
	if ((*mini)->envp == NULL)
		return (ERROR);
	(*mini)->minicmd_flag = FALSE;
	(*mini)->continue_flag = FALSE;
	return (0);
}

int	main(int argc, const char **argv)
{
	t_mini	*mini;

	mini = NULL;
	if (minishell_init(&mini) == ERROR)
		exit(1);
	while (TRUE)
	{
		if (load_prompt(mini) == ERROR)
			exit(1);
		if (ft_prompt(mini) == ERROR)
			exit(1);
	}
	return (0);
}
