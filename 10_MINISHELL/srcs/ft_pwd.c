/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:57:37 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/25 00:56:05 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_mini *mini, char **argv)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
		printf("%s\n", cwd);
	else if (cwd == NULL)
		error_msg(argv[0], argv[1], strerror(errno));
	free(cwd);
	exit_num_set(EXIT_SUCCESS);
}
