/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:57:37 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 17:38:09 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_mini *mini, char **argv)
{
	char	*cwd;

	mini->minicmd_flag = TRUE;
	if (argv[1] != NULL)
		too_many_arguments(argv[1]);
	else
	{
		cwd = getcwd(NULL, 0);
		if (cwd)
			printf("%s\n", cwd);
		else if (cwd == NULL)
			error_msg("pwd", strerror(errno));
		free(cwd);
	}
}
