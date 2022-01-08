/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/08 19:09:00 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_path(char *argv)
{
	char	*ptr;

	ptr = NULL;
	if (argv == NULL)
		ptr = getenv("HOME");
	if (ft_strncmp(argv, "~", 2) == 0)
		ptr = getenv("HOME");
	else
		return (argv);
	return (ptr);
}

void	ft_cd(t_mini *mini, char **argv)
{
	char	*path;
	char	*env_path;
	int		i;

	mini->minicmd_flag = TRUE;
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '$')
		{
			path = get_path(argv[i]);
			if (chdir(path) == ERROR)
				error_msg("cd", path, strerror(errno));
			return ;
		}
		else
		{
			env_path = getenv(argv[i]);
			if (env_path != NULL)
				chdir(env_path);
		}
		i++;
	}
	chdir(getenv("HOME"));
}
