/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:45:21 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/08/04 17:14:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parse_argv(char **argv, t_arg *arg)
{
	arg->cmd_arg1 = ft_split(argv[2], ' ');
	if (arg->cmd_arg1 == NULL)
		return (IS_ERROR);
	arg->cmd_arg2 = ft_split(argv[3], ' ');
	if (arg->cmd_arg2 == NULL)
		return (IS_ERROR);
	arg->cmd1 = is_valid_cmd(arg, arg->cmd_arg1[0]);
	arg->cmd2 = is_valid_cmd(arg, arg->cmd_arg2[0]);
	if (arg->cmd1 == NULL)
	{
		write(1, "zsh: command not found: ", 24);
		write(1, arg->cmd_arg1[0], (ft_strlen(arg->cmd_arg1[0])));
		write(1, "\n", 1);
	}
	if (arg->cmd2 == NULL)
	{
		write(1, "zsh: command not found: ", 24);
		write(1, arg->cmd_arg2[0], (ft_strlen(arg->cmd_arg2[0])));
		write(1, "\n", 1);
	}
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

int	arg_init(int argc, char **argv, char **envp, t_arg **arg)
{
	if (argc < 5)
		return (IS_ERROR);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (IS_ERROR);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if (((*arg)->infile == NULL) || ((*arg)->outfile == NULL))
		return (IS_ERROR);
	if ((parse_envp_path(&((*arg)->cmd_envp), envp)) == IS_ERROR)
		return (IS_ERROR);
	if ((parse_argv(argv, *arg)) == IS_ERROR)
		return (IS_ERROR);
	return (0);
}
