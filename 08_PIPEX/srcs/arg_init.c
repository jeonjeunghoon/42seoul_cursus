/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:43:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/07/28 22:59:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	make_envp(char ***ptr, char const **envp)
{
	
}

int	make_arg(char ***ptr, int argc, char const **argv, int start_point)
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

int	parse_solo_quotation(int argc, const char **argv, const char **envp, t_arg **arg)
{
	int	start_point;

	start_point = make_arg(&((*arg)->cmd_arg1), argc, argv, 3);
	(*arg)->cmd1 = ft_strdup((*arg)->cmd_arg1[0]);
	(*arg)->cmd_envp1 = NULL;
	make_arg(&((*arg)->cmd_arg2), argc, argv, start_point);
	(*arg)->cmd2 = ft_strdup((*arg)->cmd_arg2[0]);
	(*arg)->cmd_envp2 = NULL;
	return (0);
}

int	parse_double_quotation(const char **argv, const char **envp, t_arg **arg)
{
	(*arg)->cmd_arg1 = ft_split(argv[2], ' ');
	if ((*arg)->cmd_arg1 == NULL)
		return (IS_ERROR);
	(*arg)->cmd1 = ft_strdup(((*arg)->cmd_arg1)[0]);
	(*arg)->cmd_envp1 = NULL;
	(*arg)->cmd_arg2 = ft_split(argv[3], ' ');
	if ((*arg)->cmd_arg2 == NULL)
		return (IS_ERROR);
	(*arg)->cmd2 = ft_strdup(((*arg)->cmd_arg2)[0]);
	(*arg)->cmd_envp2 = NULL;
	return (0);
}

int	arg_init(int argc, const char **argv, const char **envp, t_arg **arg)
{
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if ((*arg) == NULL)
		return (IS_ERROR);
	(*arg)->infile = ft_strdup(argv[1]);
	(*arg)->outfile = ft_strdup(argv[argc - 1]);
	if (argc == 5)
	{
		if ((parse_double_quotation(argv, arg, envp)) == IS_ERROR)
			return (IS_ERROR);
	}
	else if (argc > 5)
	{
		if ((parse_solo_quotation(argc, argv, arg, envp)) == IS_ERROR)
			return (IS_ERROR);
	}
	else
		return (IS_ERROR);
	return (0);
}
