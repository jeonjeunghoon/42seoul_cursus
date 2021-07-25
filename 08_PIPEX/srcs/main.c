/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:47:29 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/25 18:23:21 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	cmd_arg_init(t_arg *arg)
{
	arg->cmd1_arg = (char **)malloc(sizeof(char *) * 3);
	if (arg->cmd1_arg == NULL)
		return (-1);
	arg->cmd2_arg = (char **)malloc(sizeof(char *) * 3);
	if (arg->cmd2_arg == NULL)
		return (-1);
	return (0);
}

int	parse_cmd(const char **argv, t_arg **arg)
{
	char	**split_cmd;

	split_cmd = ft_split(argv[2], ' ');
	if (split_cmd == NULL)
		return (-1);
	if ((cmd_arg_init(*arg)) == -1)
		return (-1);
	(*arg)->path1 = ft_strjoin("/bin/", split_cmd[0]);
	(*arg)->cmd1_arg[0] = ft_strdup(split_cmd[0]);
	(*arg)->cmd1_arg[1] = ft_strdup(split_cmd[1]);
	(*arg)->cmd1_arg[2] = NULL;
	free_two_dimension(split_cmd);
	split_cmd = ft_split(argv[3], ' ');
	(*arg)->path2 = ft_strjoin("/bin/", split_cmd[0]);
	(*arg)->cmd2_arg[0] = ft_strdup(split_cmd[0]);
	(*arg)->cmd2_arg[1] = ft_strdup(split_cmd[1]);
	(*arg)->cmd2_arg[2] = NULL;
	free_two_dimension(split_cmd);
	return (0);
}

int	arg_init(int argc, const char **argv, t_arg **arg)
{
	if (argc != 5)
		return (-1);
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (-1);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[4]);
	if ((parse_cmd(argv, arg)) == -1)
		return (-1);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_arg	*arg;

	if ((arg_init(argc, argv, &arg)) == -1)
		ft_exit("Error\n");
	if ((redirect(arg)) == -1)
		ft_exit("Error\n");
	// free_all(&arg);
	return (0);
}
