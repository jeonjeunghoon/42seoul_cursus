/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:45:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/02 21:09:19 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parse_argv(const char **argv, t_arg *arg)
{
	int	start_point;

	arg->cmd_arg1 = ft_split(argv[2], ' ');
	start_point = 3;
	if (ft_veclen(arg->cmd_arg1) < 1)
	{
		free_cmd_arg(arg->cmd_arg1);
		start_point = make_arg(&(arg->cmd_arg1), argv, 3);
	}
	if (arg->cmd_arg1 == NULL)
		return (IS_ERROR);
	arg->cmd_arg2 = ft_split(argv[start_point], ' ');
	if (ft_veclen(arg->cmd_arg2) < 1)
	{
		free_cmd_arg(arg->cmd_arg2);
		make_arg(&(arg->cmd_arg2), argv, start_point);
	}
	if (arg->cmd_arg2 == NULL)
		return (IS_ERROR);
	arg->cmd1 = make_cmd_path(arg, arg->cmd_arg1[0]);
	arg->cmd2 = make_cmd_path(arg, arg->cmd_arg2[0]);
	return (0);
}

int	parse_envp_path(char ***ptr, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if ((ft_strnstr(envp[i], "PATH=", 6) == envp[i]))
			break ;
		i++;
	}
	if ((i == ft_veclen((char **)envp)) || ft_veclen((char **)envp) == IS_ERROR)
		return (IS_ERROR);
	(*ptr) = ft_split(&(envp[i][5]), ':');
	return (0);
}

int	arg_init(int argc, const char **argv, char **envp, t_arg **arg)
{
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (IS_ERROR);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if (((*arg)->infile == NULL) || ((*arg)->outfile == NULL))
		return (IS_ERROR);
	if ((parse_envp_path(&((*arg)->cmd_envp), envp)) == IS_ERROR)
		return (IS_ERROR);
	if (argc < 5)
		return (IS_ERROR);
	if ((parse_argv(argv, *arg)) == IS_ERROR)
		return (IS_ERROR);
	return (0);
}
