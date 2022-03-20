/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_set2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:42:41 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/03 13:06:25 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	refine_file(t_argv *file)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 2);
	new_argv[1] = NULL;
	new_argv[0] = ft_strdup(file->argv[0]);
	ft_two_dimension_free(&file->argv);
	file->argv = new_argv;
}

char	**modify_file_argv(t_argv *file)
{
	char	**cmd_argv;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_two_dimension_size(file->argv) - 1;
	if (len == 0)
		return (NULL);
	cmd_argv = (char **)malloc(sizeof(char *) * (len + 1));
	cmd_argv[len] = NULL;
	i = 1;
	j = 0;
	while (j < len && file->argv[i] != NULL)
	{
		cmd_argv[j] = ft_strdup(file->argv[i]);
		i++;
		j++;
	}
	refine_file(file);
	return (cmd_argv);
}

char	**create_cmd(t_argv *argv, t_argv *file)
{
	char	**cmd;
	char	**cmd_argv;

	cmd_argv = modify_file_argv(file);
	if (argv->argv[0][0] == '>' || argv->argv[0][0] == '<')
	{
		if (cmd_argv == NULL)
		{
			cmd = (char **)malloc(sizeof(char *) * 2);
			cmd[1] = NULL;
			cmd[0] = ft_strdup("");
		}
		else
			cmd = ft_strsdup(cmd_argv);
	}
	else
	{
		if (cmd_argv == NULL)
			cmd = ft_strsdup(argv->argv);
		else
			cmd = ft_strsjoin(argv->argv, cmd_argv);
	}
	if (cmd_argv != NULL)
		ft_two_dimension_free(&cmd_argv);
	return (cmd);
}

void	finish_create(t_argv *argv, char ***cmd, char ***redirect_file)
{
	ft_two_dimension_free(&argv->argv);
	argv->argv = ft_strsjoin(*cmd, *redirect_file);
	ft_two_dimension_free(cmd);
	ft_two_dimension_free(redirect_file);
	argv->is_redirect = TRUE;
}

void	cmd_argv_exist(char ***cmd, char ***cmd_argv, char ***tmp)
{
	*tmp = ft_strsjoin(*cmd, *cmd_argv);
	ft_two_dimension_free(cmd);
	ft_two_dimension_free(cmd_argv);
	*cmd = ft_strsdup(*tmp);
	ft_two_dimension_free(tmp);
}
