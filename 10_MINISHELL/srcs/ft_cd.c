/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/10 13:04:59 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_path(char *argv)
{
	char	*ptr;

	ptr = NULL;
	if (argv[0] == '$')
		ptr = getenv(argv);
	else
	{
		if (argv == NULL || ft_strncmp(argv, "~", 2) == 0)
			ptr = getenv("HOME");
		else
			return (argv);
	}
	return (ptr);
}

void	ft_cd(t_mini *mini, char **argv)
{
	char	*path;
	int		check;
	int		i;

	mini->minicmd_flag = TRUE;
	check = 0;
	i = 1;
	while (argv[i])
	{
		path = get_path(argv[i]);
		if (path != NULL)
		{
			check = chdir(path);
			if (check == ERROR)
				error_msg("cd", path, strerror(errno));
			return ;
		}
		i++;
	}
	chdir(getenv("HOME"));
}
