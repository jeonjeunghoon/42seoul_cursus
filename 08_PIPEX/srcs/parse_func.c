/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:43:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/02 21:09:23 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_cmd_arg(char **cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i])
	{
		free(cmd_arg[i]);
		i++;
	}
	free(cmd_arg);
}

char	*make_cmd_path(t_arg *arg, char *arg_cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*cmd;

	path_cmd = ft_strjoin("/", arg_cmd);
	fd = 0;
	i = 0;
	while (arg->cmd_envp[i])
	{
		cmd = ft_strjoin(arg->cmd_envp[i], path_cmd);
		fd = access(cmd, X_OK);
		if (fd != -1)
			return (cmd);
		close(fd);
		free(cmd);
		i++;
	}
	write(1, "command not found\n", 19);
	return (arg_cmd);
}

int	make_arg(char ***ptr, char const **argv, int start_point)
{
	int	len;
	int	i;
	int	j;

	len = 1;
	i = start_point;
	while (argv[i][0] == '-' && argv[i])
	{
		i++;
		len++;
	}
	(*ptr) = (char **)malloc(sizeof(char *) * (len + 1));
	if (*ptr == NULL)
		return (IS_ERROR);
	j = 0;
	while (j < len)
	{
		(*ptr)[j] = ft_strdup(argv[start_point - 1]);
		j++;
		start_point++;
	}
	(*ptr)[len] = NULL;
	return (start_point);
}
