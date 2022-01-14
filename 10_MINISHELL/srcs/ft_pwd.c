/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:57:37 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/14 16:27:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_mini *mini, char **argv)
{
	char	*cwd;

	mini->flag->minicmd_flag = TRUE;
	cwd = getcwd(NULL, 0);
	if (cwd)
		printf("%s\n", cwd);
	else if (cwd == NULL)
		error_msg(argv[0], argv[1], strerror(errno));
	free(cwd);
}
