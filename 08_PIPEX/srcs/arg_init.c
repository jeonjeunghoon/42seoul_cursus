/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:43:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/26 17:22:45 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parse_cmd(const char **argv, t_arg **arg)
{
	(*arg)->cmd_arg1 = (char *const *)ft_split(argv[2], ' ');
	if ((*arg)->cmd_arg1 == NULL)
		return (-1);
	(*arg)->cmd_envp1 = NULL;
	(*arg)->path1 = ft_strjoin("/bin/", ((*arg)->cmd_arg1)[0]);
	(*arg)->cmd_arg2 = (char *const *)ft_split(argv[2], ' ');
	if ((*arg)->cmd_arg2 == NULL)
		return (-1);
	(*arg)->cmd_envp2 = NULL;
	(*arg)->path2 = ft_strjoin("/bin/", ((*arg)->cmd_arg2)[0]);
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
