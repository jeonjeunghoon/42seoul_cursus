/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:33 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/20 11:27:34 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_env_cd(t_mini *mini, char *old_pwd)
{
	t_argv	argvt;
	char	**argv;
	char	*pwd;
	int		i;

	argv = (char **)malloc(sizeof(char *) * 4);
	argv[3] = NULL;
	argv[0] = ft_strdup("export");
	pwd = getcwd(NULL, 0);
	argv[1] = ft_strjoin("PWD=", pwd);
	ft_free(&pwd);
	argv[2] = ft_strjoin("OLDPWD=", old_pwd);
	argvt.argv = argv;
	ft_export(mini, &argvt);
	i = 0;
	while (i < 4)
	{
		ft_free(&(argv[i]));
		i++;
	}
	free(argv);
	argv = NULL;
}

int	check_path(char *path)
{
	if (chdir(path) == ERROR)
	{
		error_2("cd", path, strerror(errno), 1);
		exit_num_set(1);
		return (ERROR);
	}
	return (0);
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

void	ft_cd(t_mini *mini, t_argv *argv)
{
	char	*path;
	char	*old_pwd;
	int		i;

	exit_num_set(0);
	path = NULL;
	i = 1;
	old_pwd = ft_getenv(mini->export_list, "PWD");
	while (argv->argv[i])
	{
		path = get_path(mini->export_list, argv->argv[i]);
		if (check_path(path) == ERROR)
			return ;
		i++;
	}
	set_env_cd(mini, old_pwd);
}
