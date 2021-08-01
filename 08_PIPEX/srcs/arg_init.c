/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:43:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/01 23:10:24 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

int	parse_solo_quotation(const char **argv, t_arg **arg)
{
	int	start_point;

	start_point = 0;
	start_point = make_arg(&((*arg)->cmd_arg1), argv, 3);
	make_arg(&((*arg)->cmd_arg2), argv, start_point);
	(*arg)->cmd1 = make_cmd_path((*arg), (*arg)->cmd_arg1[0]);
	(*arg)->cmd2 = make_cmd_path((*arg), (*arg)->cmd_arg2[0]);
	return (0);
}

int	parse_double_quotation(const char **argv, t_arg **arg)
{
	(*arg)->cmd_arg1 = ft_split(argv[2], ' ');
	if ((*arg)->cmd_arg1 == NULL)
		return (IS_ERROR);
	(*arg)->cmd_arg2 = ft_split(argv[3], ' ');
	if ((*arg)->cmd_arg2 == NULL)
		return (IS_ERROR);
	(*arg)->cmd1 = make_cmd_path((*arg), (*arg)->cmd_arg1[0]);
	(*arg)->cmd2 = make_cmd_path((*arg), (*arg)->cmd_arg2[0]);
	return (0);
}

int	parse_envp_path(char ***ptr, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && \
			envp[i][3] == 'H' && envp[i][4] == '=')
			break ;
		i++;
	}
	if ((i == ft_veclen((char **)envp)) || ft_veclen((char **)envp) == IS_ERROR)
		return (IS_ERROR);
	(*ptr) = ft_split(&(envp[i][5]), ':');
	return (0);
}
