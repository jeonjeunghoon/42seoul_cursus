/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/24 22:39:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_env_cd(t_mini *mini, char *pwd, char *old_pwd)
{
	char	**argv;

	// $OLDPWD에 $PWD넣기
	
	ft_export(mini, argv);
}

char	*get_path(char **envp, char *argv)
{
	char	*ptr;

	ptr = NULL;
	if (argv[0] == '$')
		ptr = ft_getenv(envp, &(argv[1]));
	else
	{
		if (argv == NULL || ft_strncmp(argv, "~", 2) == 0)
			ptr = ft_getenv(envp, "HOME");
		else
			return (argv);
	}
	return (ptr);
}

void	ft_cd(t_mini *mini, char **argv)
{
	char	*path;
	char	*old_pwd;
	int		check;
	int		i;

	mini->flag->minicmd_flag = TRUE;
	check = 0;
	i = 1;
	while (argv[i])
	{
		path = get_path(mini->envp, argv[i]);
		if (path != NULL)
		{
			old_pwd = ft_getenv(mini->envp, "PWD");
			check = chdir(path);
			if (check == ERROR)
			{
				error_msg("cd", path, strerror(errno));
				exit_num_set(1);
				return ;
			}
			break ;
		}
		i++;
	}
	if (path == NULL)
		chdir(ft_getenv(mini->envp, "HOME"));
	// set_env_cd(mini, path, old_pwd);
	exit_num_set(EXIT_SUCCESS);
}
